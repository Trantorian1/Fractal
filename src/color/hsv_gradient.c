/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:39:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 21:42:17 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsv_gradient.h"

#include "hsv_to_rgb.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

#define RANGE_HUE 360.0
#define RANGE_VALUE 0.7

static double	hue(double index, double density, double h0)
{
	return (fmod(RANGE_HUE * index / density + h0, RANGE_HUE));
}

static double	value(double index, double density)
{
	return (1 -index / density);
}

int32_t	*hsv_gradient(uint32_t density, double h0)
{
	int32_t			*gradient;
	uint32_t		index;
	double			h;
	const double	s = RANGE_VALUE;
	double			v;

	gradient = ft_malloc(density * sizeof(*gradient));
	index = 0;
	while (index < density)
	{
		h = hue(index, density, h0);
		v = value(index, density);
		// printf("h:%f, s:%f, v:%f\n", h, s, v);
		gradient[index] = hsv_to_rgb(h, s, v);
		index++;
	}
	return (gradient);
}
