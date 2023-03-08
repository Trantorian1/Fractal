* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:25:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 12:08:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_rectangles.h"

#include "draw_rectangle.h"
#include "paint.h"
#include "get_pixel.h"
#include "libft.h"
#include <stdlib.h>

#ifndef RECTANGLE_MIN_SIZE
# define RECTANGLE_MIN_SIZE 4
#endif

static void	recursive_pass(t_s_data *data, t_s_vec2d *origin, int32_t size);

static int32_t	trace_edge(
	t_s_data	*data,
	t_s_vec2d	*start,
	t_s_vec2d	*increment,
	int32_t l)
{
	int32_t		bail_prev;
	int32_t		bail_curr;
	t_s_vec2d	end;

	end.x = start->x + increment->x * l;
	end.y = start->y + increment->y * l;
	bail_prev = data->fractal->color(data->fractal->series(data, start));
	bail_curr = data->fractal->color(data->fractal->series(data, &end));
	paint(data, start, bail_prev);
	paint(data, &end, bail_curr);
	if (bail_prev == bail_curr)
		return (l);
	bail_curr = bail_prev;
	end.x = start->x + increment->x;
	end.y = start->y + increment->y;
	while (bail_prev == bail_curr
		&& max(end.x - start->x, end.y - start->y) < l)
	{
		bail_prev = bail_curr;
		bail_curr = data->fractal->color(data->fractal->series(data, &end));
		paint(data, &end, bail_curr);
		end.x += increment->x;
		end.y += increment->y;
	}
	return (max(end.x - start->x, end.y - start->y));
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

static void	recursive_pass(t_s_data *data, t_s_vec2d *origin, int32_t size)
{
	int32_t			i;
	t_s_vec2d		cursor;
	t_s_vec2d		increment;
	const t_s_vec2d	increment_map[4] = {{.x = 1, .y = 0}, {.x = 0, .y = 1},
										{.x = -1, .y = 0}, {.x = 0, .y = -1}};

	i = 0;
	cursor.x = origin->x;
	cursor.y = origin->y;
	while (i < size * 4)
	{
		increment = increment_map[i / size];
		i += trace_edge(data, &cursor, &increment, size);
		if (i % size != 0)
		{
			if (size <= RECTANGLE_MIN_SIZE)
				handle_fail(data, origin, size);
			recurse(data, origin, size);
			return ;
		}
		cursor.x = increment.x * size;
		cursor.y = increment.y * size;
	}
	draw_rectangle(data, origin, size, *(int *)get_pixel(data, &cursor));
}

// void	render_rectangles(t_s_data *data, t_s_symetry *symmetry)
void	render_rectangles(t_s_data *data)
{
	if (data == NULL)
		return ;
}
