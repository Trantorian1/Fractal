/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:09:22 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 13:03:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

#include "libft.h"

#define MOVE_RATIO 0.01

void	move(t_s_data *data, t_s_vec2d_d *direction)
{
	t_s_vec2d_d		delta_origin;
	const double	delta_pos = data->view_fractal->width * MOVE_RATIO;

	vec2d_copy_d(&delta_origin, direction);
	vec2d_scale_d(&delta_origin, delta_pos);
	vec2d_add_d(&data->view_fractal->origin, &delta_origin);
	data->trigger_render = true;
}
