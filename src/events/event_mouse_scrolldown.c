/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_scrolldown.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:33:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:16:21 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_scrolldown.h"

#include "is_key_pressed.h"
#include "decrease_iter.h"
#include "zoom.h"
#include <stdlib.h>
#include <X11/keysym.h>

int	event_mouse_scrolldown(int32_t button, int32_t x, int32_t y, t_s_data *data)
{
	t_s_vec2d_d	mouse;

	if (is_key_pressed(data, XK_Control_L))
	{
		decrease_iter(data);
		return (EXIT_SUCCESS);
	}
	(void)button;
	mouse.x = x;
	mouse.y = y;
	zoom(data, 1 / data->zoom->zoom_factor, &mouse);
	return (EXIT_SUCCESS);
}
