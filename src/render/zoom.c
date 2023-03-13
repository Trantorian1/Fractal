/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:45:06 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 16:03:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoom.h"

#include "to_fractal_space.h"
#include "mlx.h"
#include <stdio.h>

void	zoom(t_s_data *data, t_s_vec2d_d *mouse)
{
	double		scale_factor;
	double		new_width;
	double		new_ratio;
	t_s_vec2d_d	origin_old;
	t_s_vec2d_d	origin_new;

	scale_factor = data->scale_factor;
	new_width = data->view_fractal->width * data->scale_factor;
	new_ratio = new_width / data->view_screen->width;
	vec2d_copy_d(&origin_old, &data->view_fractal->origin);
	origin_new.x = mouse->x * data->view_ratio * (1 - scale_factor) + origin_old.x;
	origin_new.y = mouse->y * data->view_ratio * (scale_factor - 1) + origin_old.y;
	data->view_fractal->width = new_width;
	data->view_fractal->origin.x = origin_new.x;
	data->view_fractal->origin.y = origin_new.y;
	data->view_ratio = new_ratio;
	data->trigger_render = true;
}
