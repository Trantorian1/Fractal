/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:45:06 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 12:22:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zoom.h"

#include "to_fractal_space.h"
#include "mlx.h"

static void	calculate_zoom(
	t_s_data *data,
	t_s_vec2d_d *delta_pos,
	double *new_width,
	double *new_height)
{
	t_s_vec2d	tmp;
	t_s_vec2d_d	mouse_pos;

	*new_width = data->view_fractal.width * data->scale_factor;
	data->view_fractal.height = data->view_screen.height * data->ratio;
	*new_height = data->view_fractal.height * data->scale_factor;
	mlx_mouse_get_pos(data->mlx, data->main_window, &tmp.x, &tmp.y);
	mouse_pos.x = (double)tmp.x;
	mouse_pos.y = (double)tmp.y;
	to_fractal_space(data, &mouse_pos, mouse_pos, data->ratio);
	delta_pos->x = mouse_pos.x - *new_width / 2;
	delta_pos->y = mouse_pos.y - *new_height / 2;
}

static void	apply_zoom(
	t_s_data *data,
	t_s_vec2d_d *delta_pos,
	double new_width)
{
	data->view_fractal.width = new_width;
	vec2d_add_d(&data->view_fractal.origin, *delta_pos);
}

void	zoom(t_s_data *data)
{
	double		new_width;
	double		new_height;
	t_s_vec2d_d	delta_pos;

	calculate_zoom(data, &delta_pos, &new_width, &new_height);
	apply_zoom(data, &delta_pos, new_width);
}
