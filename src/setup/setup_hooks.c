/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:49:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:55:45 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file setup_hooks.c
 * @brief Handles event hook registration.
 */

#include "setup_hooks.h"

#include "event_destroy.h"
#include "event_keypress.h"
#include "event_keyrelease.h"
#include "event_do_nothing.h"
#include "event_mouse_down.h"
#include "event_mouse_up.h"
#include "event_mouse_move.h"
#include "renderer.h"
#include "mlx.h"
#include <X11/X.h>

/**
 * @brief Registers all event hooks used throughout the application.
 *
 * Registered events are:
 * - loop event
 * - destroy event
 * - keypress event
 *
 * @param data (t_s_data *): global graphics context data, used to register
 * events.
 */
void	setup_hooks(t_s_data *data)
{
	void	*window;

	if (data == NULL)
		return ;
	window = data->main_window;
	mlx_loop_hook(data->mlx, &renderer, data);
	mlx_hook(window, DestroyNotify, NoEventMask, &event_destroy, data);
	mlx_hook(window, KeyPress, KeyPressMask, &event_keypress, data);
	mlx_hook(window, KeyRelease, KeyReleaseMask, &event_keyrelease, data);
	mlx_mouse_hook(window, &event_mouse_down, data);
	mlx_hook(window, ButtonRelease, ButtonReleaseMask, &event_mouse_up, data);
	mlx_hook(window, MotionNotify, Button1MotionMask, &event_mouse_move, data);
}
