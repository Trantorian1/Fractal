/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_scrollup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:31:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:20:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_scrollup.h"

#include "is_key_pressed.h"
#include "increase_iter.h"
#include "zoom.h"
#include <X11/keysym.h>
#include <stdlib.h>

int	event_mouse_scrollup(int32_t button, int32_t x, int32_t y, t_s_data *data)
{
	t_s_vec2d_d	mouse;

	if (is_key_pressed(data, XK_Control_L))
	{
		increase_iter(data);
		return (EXIT_SUCCESS);
	}
	(void)button;
	mouse.x = x;
	mouse.y = y;
	zoom(data, data->zoom->zoom_factor, &mouse);
	return (EXIT_SUCCESS);
}
