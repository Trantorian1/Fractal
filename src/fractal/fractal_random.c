/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_random.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:52:42 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 17:54:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_random.h"

#include <time.h>
#include <stdlib.h>
#include <stdint.h>

static int32_t	fractal_color(int32_t bail)
{
	(void)bail;
	return (bail % 256);
}

static int32_t	fractal_series(t_s_data *data, t_s_vec2d_d *vect)
{
	(void)data;
	(void)vect;
	return (rand() % 1000);
}

t_s_fractal	*fractal_random(void)
{
	static t_s_fractal	fractal;

	fractal.bottom.x = 0;
	fractal.bottom.y = 10;
	fractal.series = &fractal_series;
	fractal.color = &fractal_color;
	return (&fractal);
}
