/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:49:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 13:12:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_hooks.h"

#include "event_destroy.h"
#include "event_keypress.h"
#include "event_do_nothing.h"
#include "renderer.h"
#include "mlx.h"
#include <X11/X.h>
#include "stdlib.h"

void	setup_hooks(t_s_data *data)
{
	void	*window;

	if (data == NULL)
		return ;
	window = data->main_window;
	mlx_loop_hook(data->mlx, renderer, data);
	mlx_hook(window, DestroyNotify, NoEventMask, event_destroy, data);
	mlx_hook(window, KeyPress, KeyPressMask, event_keypress, data);
}
