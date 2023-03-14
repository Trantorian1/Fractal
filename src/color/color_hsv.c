/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hsv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:59:03 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:59:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color_hsv.h"

#include "hsv_gradient.h"
#include <math.h>
#include <stdio.h>

#define HUE_START 0

int32_t	color_hsv(t_s_data *data, double iter)
{
	static int32_t	*gradient = NULL;
	double			powi;
	double			powz;
	int32_t			index;

	if (gradient == NULL)
		gradient = hsv_gradient((uint32_t)data->fractal->max_iter, HUE_START);
	if (iter >= data->fractal->max_iter)
		return (0x0);
	powi = pow(iter / data->fractal->max_iter, 2.0);
	powz = pow(powi * data->fractal->max_iter, 1.5);
	index = (int32_t)powz % data->fractal->max_iter_initial;
	return (gradient[index]);
}
