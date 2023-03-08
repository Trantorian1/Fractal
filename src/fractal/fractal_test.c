/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:25:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 17:54:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_test.h"

#include "s_data.h"
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
	return (0xff);
}

t_s_fractal	*fractal_test(void)
{
	static t_s_fractal			fractal;

	fractal.series = &fractal_series;
	fractal.color = &fractal_color;
	return (&fractal);
}
