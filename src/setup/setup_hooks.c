/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:49:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 17:15:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_hooks.h"

#include "event_destroy.h"
#include "event_keypress.h"
#include "event_do_nothing.h"
#include "mlx.h"
#include <X11/X.h>
#include "stdlib.h"

void	setup_hooks(t_s_data *data)
{
	if (data == NULL)
		return ;
	mlx_loop_hook(data->mlx, event_do_nothing, &data);
	mlx_hook(data->main_window, DestroyNotify, NoEventMask, event_destroy, data);
	mlx_hook(data->main_window, KeyPress, KeyPressMask, event_keypress, data);
}
