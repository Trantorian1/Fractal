/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_random.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:42 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 16:42:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_random.h"

#include "stdlib.h"
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

static double	fractal_series(t_s_data *data, t_s_vec2d_d vect)
{
	(void)vect;
	return (rand() % data->fractal->max_iter);
}

static int32_t	fractal_color(t_s_data *data, double bail)
{
	(void)data;
	return ((int)bail % 256);
}

t_s_fractal	*fractal_random(void)
{
	static t_s_fractal	fractal;
	static t_s_vec2d_d	origin = {.x = 0.0, .y = 0.0};

	fractal.series = &fractal_series;
	fractal.color = &fractal_color;
	fractal.view_initial.width = 1024;
	fractal.max_iter = 1000;
	vec2d_copy_d(&fractal.view_initial.origin, origin);
	return (&fractal);
}
