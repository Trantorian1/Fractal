/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_screen_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:03:27 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 18:33:00 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_screen_coords.h"

#include "libft.h"

t_s_vec2d_d	*to_screen_coords(t_s_data *data, t_s_vec2d_d *fractal_coords)
{
	double	width_fractal;
	double	width_screen;
	double	ratio;

	if (data == NULL || fractal_coords == NULL)
		return (NULL);
	width_fractal = (data->bounds.x - data->bounds.o);
	width_screen = data->dimension.x;
	ratio = width_screen / width_fractal;
	fractal_coords->x *= ratio;
	fractal_coords->y *= ratio;
	return (fractal_coords);
}
