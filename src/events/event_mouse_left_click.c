/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_left_click.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:14:25 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 18:17:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_left_click.h"

#include <stdio.h>
#include <stdlib.h>

int	event_mouse_left_click(int32_t button, int32_t x, int32_t y, t_s_data *data)
{
	(void)button;
	(void)x;
	(void)y;
	data->panning->last_pos.x = x;
	data->panning->last_pos.y = y;
	data->panning->is_panning = true;
	return (EXIT_SUCCESS);
}
