/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:25:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 19:38:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_rectangles.h"

#include "paint.h"
#include "get_pixel.h"
#include "draw_square.h"
#include "libft.h"
#include <stdlib.h>

#ifndef RECTANGLE_MIN_SIZE
# define RECTANGLE_MIN_SIZE 16
#endif

static bool	recursive_pass(t_s_data *data, t_s_vec2d_d *origin, double l);

static int32_t	trace_edge(
	t_s_data	*data,
	t_s_vec2d_d	*start,
	t_s_vec2d_d	*increment,
	int32_t l)
{
	int32_t		bail_prev;
	int32_t		bail_curr;
	t_s_vec2d_d	end;
	t_s_vec2d_d	screen;

	end.x = start->x + increment->x * l;
	end.y = start->y + increment->y * l;
	bail_prev = data->fractal->color(data->fractal->series(data, start));
	bail_curr = data->fractal->color(data->fractal->series(data, &end));
	paint(data, start, bail_prev);
	if (bail_prev == bail_curr && *(int *)get_pixel(data, &end) != 0)
		return (l);
	bail_curr = bail_prev;
	end.x = start->x + increment->x;
	end.y = start->y + increment->y;
	while (bail_prev == bail_curr
		&& max(abs(end.x - start->x), abs(end.y - start->y)) < l)
	{
		bail_prev = bail_curr;
		bail_curr = data->fractal->color(data->fractal->series(data, &end));
		paint(data, &end, bail_curr);
		end.x += increment->x;
		end.y += increment->y;
	}
	return (max(abs(end.x - start->x), abs(end.y - start->y)));
}

static void	recurse(t_s_data *data, t_s_vec2d *origin, int32_t size)
{
	const int32_t	size_child = size / 2;
	t_s_vec2d		origin_child;

	origin_child.x = origin->x;
	origin_child.y = origin->y;
	recursive_pass(data, &origin_child, size_child);
	origin_child.x += size_child;
	recursive_pass(data, &origin_child, size_child);
	origin_child.y += size_child;
	recursive_pass(data, &origin_child, size_child);
	origin_child.x -= size_child;
	recursive_pass(data, &origin_child, size_child);
}

static void	handle_fail(t_s_data *data, t_s_vec2d *origin, int32_t size)
{
	t_s_vec2d	cursor;
	int32_t		pixel_bail;
	int32_t		pixel_color;

	cursor.x = origin->x;
	while ((cursor.x - origin->x) < size)
	{
		cursor.y = origin->y;
		while ((cursor.y - origin->y) < size)
		{
			pixel_bail = data->fractal->series(data, &cursor);
			pixel_color = data->fractal->color(pixel_bail);
			paint(data, &cursor, pixel_color);
			cursor.y++;
		}
		cursor.x++;
	}
	cursor.y = origin->y;
}

static bool	recursive_pass(t_s_data *data, t_s_vec2d_d *origin, double l)
{
	double				delta;
	int32_t				i;
	t_s_vec2d_d			cursor;
	t_s_vec2d_d			increment;
	static t_s_vec2d_d	increment_map[4] = {{.x = 1.0, .y = 0.0},
	{.x = 0.0, .y = 1.0}, {.x = -1.0, .y = 0.0}, {.x = 0.0, .y = -1.0}};

	delta = data->view_screen / data->dimension.x;
	i = 0;
	while (i < 4)
	{
		increment_map[i].x *= delta;
		increment_map[i].y *= delta;
		i++;
	}
	i = 0;
	cursor.x = origin->x;
	cursor.y = origin->y;
	while (i < l * 4)
	{
		increment = increment_map[i / l];
		i += trace_edge(data, &cursor, &increment, l);
		if (i % l != 0)
		{
			if (l <= RECTANGLE_MIN_SIZE)
				handle_fail(data, origin, l);
			else
				recurse(data, origin, l);
			return (false);
		}
		cursor.x += increment.x * l;
		cursor.y += increment.y * l;
	}
	draw_square(data, origin, l, *(int *)get_pixel(data, &cursor));
	return (true);
}

// void	render_rectangles(t_s_data *data, t_s_symetry *symmetry)
void	render_rectangles(t_s_data *data)
{
	t_s_vec2d_d	origin;
	double		l;

	if (data == NULL)
		return ;
	origin.x = 0.0;
	origin.y = 0.0;
	l = max_d(data->view_screen.width, data->view_screen.height);
	recursive_pass(data, &origin, l);
}
