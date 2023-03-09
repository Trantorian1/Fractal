/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:25:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 13:19:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_test.h"

#include "libft.h"
#include <stdint.h>

static int32_t	fractal_series(t_s_data *data, t_s_vec2d_d vect)
{
	(void)data;
	(void)vect;
	return (0xff);
}

static int32_t	fractal_color(int32_t bail)
{
	(void)bail;
	return (bail % 256);
}

t_s_fractal	*fractal_test(void)
{
	static t_s_fractal	fractal;
	static t_s_vec2d_d	origin = {.x = 0.0, .y = 0.0};

	fractal.series = &fractal_series;
	fractal.color = &fractal_color;
	fractal.view_initial.width = 1024.0;
	vec2d_copy_d(&fractal.view_initial.origin, origin);
	return (&fractal);
}