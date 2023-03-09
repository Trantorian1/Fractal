/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:25:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 13:00:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_rectangles.h"

#include "render_edge.h"
#include "render_fill.h"
#include "paint.h"
#include "get_pixel.h"
#include "libft.h"

#ifndef RECTANGLE_MIN_SIZE
# define RECTANGLE_MIN_SIZE 16
#endif

static void	recursive_draw(
				t_s_data *data,
				t_s_vec2d_d origin,
				int32_t len);

static void	handle_fail(
	t_s_data *data,
	t_s_vec2d_d origin,
	int32_t len
	)
{
	t_s_vec2d_d	in_screen;
	t_s_vec2d_d	in_fractal;
	int32_t		bailout;
	int32_t		color;

	vec2d_copy_d(&in_screen, origin);
	vec2d_mult_d(vec2d_copy_d(&in_fractal, in_screen), data->ratio);
	while ((in_screen.x - origin.x) < len)
	{
		while ((in_screen.y - origin.y) < len)
		{
			bailout = data->fractal->series(data, in_fractal);
			color = data->fractal->color(bailout);
			paint(data, in_screen, color);
			in_fractal.y += data->ratio;
			in_screen.y++;
		}
		in_fractal.x += data->ratio;
		in_screen.x++;
	}
}

static void	render_children(
	t_s_data *data,
	t_s_vec2d_d origin,
	int32_t len
)
{
	const int32_t	len_child = len / 2;

	recursive_draw(data, origin, len_child);
	origin.x += len_child;
	recursive_draw(data, origin, len_child);
	origin.y += len_child;
	recursive_draw(data, origin, len_child);
	origin.x -= len_child;
	recursive_draw(data, origin, len_child);
}

/**
 * @brief Recursively tries to fill smaller and smaller rectangles.
 *
 * Rectangles are continuous zones with the same bail, where only the edges
 * need to be calcualted to infer the color of the interior.
 *
 * @param data (t_s_data *): screen data.
 * @param origin (t_s_vec2d_d *): starting coordinates in screen space.
 * @param len (double): length or the rectangle to draw.
 */
static void	recursive_draw(
	t_s_data *data,
	t_s_vec2d_d origin,
	int32_t len)
{
	t_s_vec2d_d					in_screen;
	t_s_vec2d_d					incr_screen;
	int32_t						index_prev;
	int32_t						index_curr;
	const static t_s_vec2d_d	increment_map[4] = {{.x = 1.0, .y = 0.0},
	{.x = 0.0, .y = 1.0}, {.x = -1.0, .y = 0.0}, {.x = 0.0, .y = -1.0}};

	vec2d_copy_d(&in_screen, origin);
	index_prev = -1;
	index_curr = 0;
	while (index_curr < len * 4)
	{
		incr_screen = increment_map[index_curr / len];
		index_curr += render_edge(data, in_screen, incr_screen);
		if (index_curr == index_prev || index_curr % len != 0)
		{
			if (len <= RECTANGLE_MIN_SIZE)
				return (handle_fail(data, origin, len));
			else
				return (render_children(data, origin, len));
		}
		index_prev = index_curr;
		vec2d_combine_d(&in_screen, incr_screen);
	}
	render_fill(data, origin, len, *(int *)get_pixel(data, in_screen));
}

void	render_rectangles(t_s_data *data)
{
	t_s_vec2d_d	origin;
	int32_t		len;
	double		ratio;

	if (data == NULL)
		return ;
	origin = data->view_screen.origin;
	len = (int32_t)data->view_screen.width;
	recursive_draw(data, origin, len);
}
