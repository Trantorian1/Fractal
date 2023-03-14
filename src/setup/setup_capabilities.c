/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_capabilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:26:15 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:33:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_capabilities.h"

#include "libft.h"

static void	setup_zoom(t_s_data *data)
{
	data->zoom = ft_malloc(sizeof(*data->zoom));
	data->zoom->zoom_factor = 0.95;
	data->zoom->zoom_scale = 1.0;
	data->zoom->zoom_count = 0;
}

static void	setup_panning(t_s_data *data)
{
	data->panning = ft_malloc(sizeof(*data->panning));
	data->panning->is_panning = false;
	data->panning->last_pos.x = 0;
	data->panning->last_pos.y = 0;
}

static void	setup_keys(t_s_data *data)
{
	data->keys = ft_malloc(sizeof(*data->keys));
	data->keys->pressed = 0x0;
	data->keys->released = 0x0;
	data->keys->modifiers = 0x0;
}

void	setup_capabilities(t_s_data *data)
{
	setup_zoom(data);
	setup_panning(data);
	setup_keys(data);
}
