/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:45:06 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 13:11:17 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoom.h"

#include "to_fractal_space.h"
#include "mlx.h"
#include <stdio.h>

void	zoom(t_s_data *data, double zoom_factor, t_s_vec2d_d *mouse)
{
	double		new_width;
	double		new_ratio;
	t_s_vec2d_d	origin_old;
	t_s_vec2d_d	origin_new;

	new_width = data->view_fractal->width * zoom_factor;
	new_ratio = new_width / data->view_screen->width;
	vec2d_copy_d(&origin_old, &data->view_fractal->origin);
	origin_new.x = mouse->x * data->view_ratio * (1 - zoom_factor) + origin_old.x;
	origin_new.y = mouse->y * data->view_ratio * (zoom_factor - 1) + origin_old.y;
	data->view_fractal->width = new_width;
	data->view_fractal->origin.x = origin_new.x;
	data->view_fractal->origin.y = origin_new.y;
	data->view_ratio = new_ratio;
	data->zoom->zoom_scale *= zoom_factor;
	data->zoom->zoom_count++;
	data->trigger_render = true;
}
