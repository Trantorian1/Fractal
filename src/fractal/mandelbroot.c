/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:13:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 13:21:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandelbroot.h"

#include "libft.h"
#include <stdint.h>

static int32_t	mandelbroot_series(t_s_data *data, t_s_vec2d_d vect)
{
	(void)data;
	(void)vect;
	return (0);
}

static int32_t	mandelbroot_color(int32_t bail)
{
	(void)bail;
	return (0xff);
}

t_s_fractal	*mandelbroot(void)
{
	static t_s_fractal	mandelbroot;
	static t_s_vec2d_d	origin = {.x = -3, .y = 3};

	mandelbroot.series = &mandelbroot_series;
	mandelbroot.color = &mandelbroot_color;
	mandelbroot.view_initial.width = 6;
	vec2d_copy_d(&mandelbroot.view_initial.origin, origin);
	return (&mandelbroot);
}
