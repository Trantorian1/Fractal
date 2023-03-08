/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_fractal_coords.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:21:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 18:33:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_fractal_coords.h"

#include "libft.h"

t_s_vec2d_d	*to_fractal_coords(t_s_data *data, t_s_vec2d_d *screen_coords)
{
	double	width_fractal;
	double	width_screen;
	double	ratio;

	if (data == NULL || screen_coords == NULL)
		return (NULL);
	width_fractal = data->bounds.x - data->bounds.o;
	width_screen = data->dimension.x;
	ratio = width_fractal / width_screen;
	screen_coords->x *= ratio;
	screen_coords->y *= ratio;
	return (screen_coords);
}
