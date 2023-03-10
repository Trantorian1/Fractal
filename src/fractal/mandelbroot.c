/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:13:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 21:03:04 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbroot.h"

#include "color_hsv.h"
#include "libft.h"
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

static bool	has_bailed(
	t_s_vec2d_d squared,
	int32_t index,
	double bail_bound,
	const t_s_fractal *mandelbroot)
{
	bool	reached_bail;
	bool	reached_iter;

	reached_bail = squared.x + squared.y > bail_bound;
	reached_iter = index >= mandelbroot->max_iter;
	return (reached_bail || reached_iter);
}

static double	mandelbroot_escape_time(t_s_data *data, t_s_vec2d_d vect)
{
	int32_t				iter;
	double				x;
	double				y;
	t_s_vec2d_d			squared;
	const t_s_fractal	*mandelbroot = data->fractal;

	iter = 0;
	x = 0;
	y = 0;
	squared.x = 0;
	squared.y = 0;
	if (vect.x * vect.x + vect.y * vect.y > mandelbroot->bail_bound)
		return (1);
	while (!has_bailed(squared, iter, mandelbroot->bail_bound, mandelbroot))
	{
		y = (x + x) * y + vect.y;
		x = squared.x - squared.y + vect.x;
		squared.x = x * x;
		squared.y = y * y;
		iter++;
	}
	return (iter);
}

t_s_fractal	*mandelbroot(void)
{
	static t_s_fractal	mandelbroot;
	static t_s_vec2d_d	origin = {.x = -3, .y = 3};

	mandelbroot.series = &mandelbroot_escape_time;
	mandelbroot.color = &color_hsv;
	mandelbroot.view_initial.width = 6;
	mandelbroot.max_iter = 500;
	mandelbroot.bail_bound = 4;
	vec2d_copy_d(&mandelbroot.view_initial.origin, origin);
	return (&mandelbroot);
}
