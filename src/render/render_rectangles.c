/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:25:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 16:23:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file render_rectangles.c
 * @brief Rendering optimisation functions.
 */

#include "render_rectangles.h"

#include "contains_fractal.h"
#include "is_in_screen.h"
#include "to_fractal_space.h"
#include "render_edge.h"
#include "render_fill.h"
#include "paint.h"
#include "get_pixel.h"
#include "libft.h"
#include <stdio.h>

#ifndef RECTANGLE_MIN_SIZE
# define RECTANGLE_MIN_SIZE 16
#endif

static void	recursive_draw(
				t_s_data *data,
				t_s_vec2d_d *origin,
				int32_t len);

/**
 * @brief Fills rectangle if rectangle checkin was not able to optimise
 * rendering at the given coordinates.
 *
 * If rectangle checking reaches minimal rectangle size and still encounters a
 * discontinuity in bail along the edge of the rectangle, renders every pixel in
 * the rectangle individually.
 *
 * @param data (t_s_data *): global graphics context.
 * @param origin (t_s_vec2d_d *): rectangle origin.
 * @param len (int32_t): rectangle length.
 */
static void	handle_fail(
	t_s_data *data,
	t_s_vec2d_d *origin,
	int32_t len
	)
{
	t_s_vec2d_d	in_screen;
	t_s_vec2d_d	in_fractal;
	double		bailout;
	int32_t		color;

	vec2d_copy_d(&in_screen, origin);
	in_fractal.x = origin->x * data->view_ratio + data->view_fractal->origin.x;
	while (is_in_screen(data, &in_screen) && (in_screen.x - origin->x) < len)
	{
		in_fractal.y = -origin->y * data->view_ratio + data->view_fractal->origin.y;
		while (is_in_screen(data, &in_screen) && (in_screen.y - origin->y) < len)
		{
			bailout = data->fractal->series(data, &in_fractal);
			color = data->fractal->color(data, bailout);
			paint(data, &in_screen, color);
			in_fractal.y -= data->view_ratio;
			in_screen.y++;
		}
		in_screen.y = origin->y;
		in_fractal.x += data->view_ratio;
		in_screen.x++;
	}
}

/**
 * @brief Recursively calls rectangle checking on all sub-rectangles in a
 * rectangle after a discontinuity in bail along the edge has been detected.
 *
 * @param data (t_s_data *): global graphics context.
 * @param origin (t_s_vec2d_d *): parent rectangle origin.
 * @param len (int32_t): parent rectangle length.
 */
static void	render_children(
	t_s_data *data,
	t_s_vec2d_d *origin,
	int32_t len
)
{
	const int32_t	len_child = len / 2;
	t_s_vec2d_d		origin_cpy;

	vec2d_copy_d(&origin_cpy, origin);
	if (is_in_screen(data, &origin_cpy))
		recursive_draw(data, &origin_cpy, len_child);
	origin_cpy.x += len_child;
	if (is_in_screen(data, &origin_cpy))
		recursive_draw(data, &origin_cpy, len_child);
	origin_cpy.y += len_child;
	if (is_in_screen(data, &origin_cpy))
		recursive_draw(data, &origin_cpy, len_child);
	origin_cpy.x -= len_child;
	if (is_in_screen(data, &origin_cpy))
		recursive_draw(data, &origin_cpy, len_child);
}

/**
 * @brief Recursively tries to fill smaller and smaller rectangles.
 *
 * Rectangles are continuous zones with the same bail, where only the edges
 * need to be calcualted to infer the color of the interior. If a pixel with a
 * different bail is detected, recursively seperates rectangle into 4
 * sub-rectangles, checking each one for continuous bail. Process stops if all
 * values along the edge of a rectangle are continuous or if a minimal rectangle
 * size has been reached.
 *
 * @param data (t_s_data *): screen data.
 * @param origin (t_s_vec2d_d *): starting coordinates in screen space.
 * @param len (double): length or the rectangle to draw.
 */
static void	recursive_draw(
	t_s_data *data,
	t_s_vec2d_d *origin,
	int32_t len)
{
	t_s_vec2d_d			in_screen;
	t_s_vec2d_d			incr_screen;
	int32_t				index_prev;
	int32_t				index_curr;
	static t_s_vec2d_d	increment_map[4] = {{.x = 1.0, .y = 0.0},
	{.x = 0.0, .y = 1.0}, {.x = -1.0, .y = 0.0}, {.x = 0.0, .y = -1.0}};

	if (contains_fractal(data, origin, len))
		return (render_children(data, origin, len));
	vec2d_copy_d(&in_screen, origin);
	index_prev = -1;
	index_curr = 0;
	while (is_in_screen(data, &in_screen) && index_curr < len * 4)
	{
		vec2d_copy_d(&incr_screen, &increment_map[index_curr / len]);
		index_curr += render_edge(data, &in_screen, &incr_screen, len);
		if (index_curr == index_prev || index_curr % len != 0)
		{
			if (len <= RECTANGLE_MIN_SIZE)
				return (handle_fail(data, origin, len));
			else
				return (render_children(data, origin, len));
		}
		index_prev = index_curr;
		vec2d_add_d(&in_screen, vec2d_scale_d(&incr_screen, len));
	}
	render_fill(data, origin, len, *(int *)get_pixel(data, &in_screen));
}

/**
 * @brief Optimisation pass in rendering, fill in continuous areas with the
 * same bailout value.
 *
 * Tries to recursively draw rectangles of diminishing sizes across the screen
 * by checking for zones of equal bailout, filling them without any extra
 * calculations.
 *
 * @param data (t_s_data *): global graphics context.
 */
void	render_rectangles(t_s_data *data)
{
	t_s_vec2d_d	origin;
	int32_t		len;

	if (data == NULL)
		return ;
	origin = data->view_screen->origin;
	len = ft_closest_power((int32_t)data->view_screen->width, 2);
	recursive_draw(data, &origin, len);
}
