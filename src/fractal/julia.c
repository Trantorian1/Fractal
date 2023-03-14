/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:15:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 16:57:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia.h"

#include "color_hsv.h"
#include "libft.h"
#include <stdio.h>

/* static bool	has_bailed(
	t_s_vec2d_d *squared,
	int32_t index,
	double bail_bound,
	const t_s_fractal *julia)
{
	bool	reached_bail;
	bool	reached_iter;

	reached_bail = squared->x + squared->y > bail_bound;
	reached_iter = index >= julia->max_iter;
	return (reached_bail || reached_iter);
} */

static double	escape_time(t_s_data *data, t_s_vec2d_d *vect)
{
	int32_t				iter;
	double				tmp;
	t_s_vec2d_d			point;
	t_s_vec2d_d			julia_param;
	const t_s_fractal	*julia = data->fractal;

	iter = 0;
	vec2d_copy_d(&point, vect);
	vec2d_copy_d(&julia_param, julia->data);
	while (point.x * point.x + point.y * point.y < 4 && iter < julia->max_iter)
	{
		tmp = point.x;
		point.x = point.x * point.x - point.y * point.y + julia_param.x;
		point.y = 2 * tmp * point.y + julia_param.y;
		iter++;
	}
	return (iter);
}

static void	julia_bounds(t_s_fractal *julia)
{
	static t_s_bounds	bounds;
	static t_s_vec2d_d	origin = {.x = -2.0, .y = 2.0};

	bounds.width = 4.0;
	bounds.height = 4.0;
	vec2d_copy_d(&bounds.origin, &origin);
	julia->bounds = &bounds;
}

t_s_fractal	*julia(void)
{
	static t_s_fractal	julia;
	static t_s_vec2d_d	julia_param = {.x = -1.0, .y = 0.0};

	julia.series = &escape_time;
	julia.color = &color_hsv;
	julia.max_iter_initial = 500;
	julia.delta_iter = 10;
	julia.bail_bound = 4;
	julia.data = &julia_param;
	julia_bounds(&julia);
	return (&julia);
}
