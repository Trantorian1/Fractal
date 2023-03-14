/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:30:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 18:31:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "panning.h"

void	panning(int x, int y, t_s_data *data)
{
	t_s_vec2d_d	origin;
	t_s_vec2d_d	delta;

	origin = data->panning->last_pos;
	delta.x = origin.x - x;
	delta.y = y - origin.y;
	vec2d_scale_d(&delta, data->view_ratio);
	vec2d_add_d(&delta, &data->view_fractal->origin);
	vec2d_copy_d(&data->view_fractal->origin, &delta);
	data->panning->last_pos.x = x;
	data->panning->last_pos.y = y;
	data->trigger_render = true;
}
