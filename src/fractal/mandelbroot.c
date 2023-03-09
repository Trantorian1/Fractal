/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:13:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:58:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbroot.h"

#include "libft.h"
#include <stdbool.h>
#include <stdint.h>

static bool	has_bailed(
	t_s_vec2d_d squared,
	int32_t index,
	t_s_fractal mandelbroot)
{
	bool	reached_bail;
	bool	reached_iter;

	reached_bail = squared.x + squared.y > mandelbroot.bail_bound;
	reached_iter = index >= mandelbroot.max_iter;
	return (reached_bail || reached_iter);
}

static int32_t	mandelbroot_series(t_s_data *data, t_s_vec2d_d vect)
{
	int32_t				index;
	double				x;
	double				y;
	t_s_vec2d_d			squared;
	const t_s_fractal	*mandelbroot = data->fractal;

	index = 0;
	x = 0;
	y = 0;
	squared.x = 0;
	squared.y = 0;
	while (!has_bailed(squared, index, *mandelbroot))
	{
		y = (x + x) * y + vect.y;
		x = squared.x + squared.y + vect.x;
		squared.x = x * x;
		squared.y = y * y;
		index++;
	}
	return (index);
}

static int32_t	mandelbroot_color(int32_t bail)
{
	return (0xff * bail / 1000);
}

t_s_fractal	*mandelbroot(void)
{
	static t_s_fractal	mandelbroot;
	static t_s_vec2d_d	origin = {.x = -3, .y = 3};

	mandelbroot.series = &mandelbroot_series;
	mandelbroot.color = &mandelbroot_color;
	mandelbroot.view_initial.width = 6;
	mandelbroot.max_iter = 1000;
	mandelbroot.bail_bound = 4;
	vec2d_copy_d(&mandelbroot.view_initial.origin, origin);
	return (&mandelbroot);
}
