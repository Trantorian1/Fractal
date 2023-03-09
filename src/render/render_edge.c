/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:49:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 12:42:05 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_edge.h"

#include "paint.h"

static int32_t	drawn(t_s_vec2d_d start, t_s_vec2d_d end)
{
	int32_t	dx;
	int32_t	dy;

	dx = abs((int32_t)(end.x - start.x));
	dy = abs((int32_t)(end.y - start.y));
	return (max(dx, dy));
}	

static t_s_vec2d_d	*to_fractal_space(
	t_s_vec2d_d *dest,
	t_s_vec2d_d source,
	double ratio)
{
	return (vec2d_mult_d(vec2d_copy_d(dest, source), ratio));
}

static int32_t	calculate_bail(
	t_s_data *data,
	t_s_vec2d_d in_fractal,
	t_s_vec2d_d in_screen)
{
	int32_t	bail;

	bail = data->fractal->color(data->fractal->series(data, in_fractal));
	paint(data, in_screen, bail);
	return (bail);
}

static void	increment(
	t_s_vec2d_d *in_screen,
	t_s_vec2d_d incr_screen,
	t_s_vec2d_d *in_fractal,
	t_s_vec2d_d incr_fractal)
{
	vec2d_combine_d(in_screen, incr_screen);
	vec2d_combine_d(in_fractal, incr_fractal);
}

int32_t	render_edge(
	t_s_data *data,
	t_s_vec2d_d start,
	t_s_vec2d_d incr_screen)
{
	t_s_vec2d_d	in_screen;
	t_s_vec2d_d	in_fractal;
	t_s_vec2d_d	incr_fractal;
	int32_t		bail_prev;
	int32_t		bail_curr;

	vec2d_copy_d(&in_screen, start);
	to_fractal_space(&incr_fractal, incr_screen, data->ratio);
	to_fractal_space(&in_fractal, start, data->ratio);
	bail_prev = calculate_bail(data, in_fractal, in_screen);
	increment(&in_screen, incr_screen, &in_fractal, incr_fractal);
	bail_curr = calculate_bail(data, in_fractal, in_screen);
	while (bail_prev == bail_curr
		&& drawn(start, in_screen) < data->view_screen.width)
	{
		increment(&in_screen, incr_screen, &in_fractal, incr_fractal);
		bail_prev = bail_curr;
		bail_curr = calculate_bail(data, in_fractal, in_screen);
	}
	return (drawn(start, in_screen));
}