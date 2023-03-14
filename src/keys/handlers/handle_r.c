/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:17:50 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:24:53 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_r.h"

#include "libft.h"

void	handle_r(t_s_data *data)
{
	t_s_view	*view_old;
	t_s_view	*view_new;

	data->fractal->max_iter = data->fractal->max_iter_initial;
	view_old = data->fractal->view_initial;
	view_new = data->view_fractal;
	vec2d_copy_d(&view_new->origin, &view_old->origin);
	view_new->width = view_old->width;
	view_new->height = view_old->height;
	data->view_ratio = view_old->width / data->view_screen->width;
	data->trigger_render = true;
}
