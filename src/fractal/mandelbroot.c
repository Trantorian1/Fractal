/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbroot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:13:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 17:05:40 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_data.h"

#include "libft.h"
#include <stdint.h>

static int32_t	mandelbroot_series(t_s_data *data, t_s_vec2d *vect)
{
}

t_s_fractal	mandelbroot(void)
{
	static t_s_fractal	mandelbroot;

	mandelbroot.ratio.x = -2.5;
	mandelbroot.ratio.y = 2.5;
}
