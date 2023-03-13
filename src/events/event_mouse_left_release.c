/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_left_release.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:36:53 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 18:15:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_left_release.h"

#include <stdio.h>
#include <stdlib.h>

int	event_mouse_left_release(
	int32_t button,
	int32_t x,
	int32_t y,
	t_s_data *data)
{
	(void)button;
	(void)x;
	(void)y;
	data->panning->is_panning = false;
	return (EXIT_SUCCESS);
}
