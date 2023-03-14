/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalise_key_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:33:21 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 11:38:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "normalise_key_function.h"

#include <X11/keysym.h>

int32_t	normalise_key_func(int keysym)
{
	if (keysym == XK_BackSpace)
		return (0);
	if (keysym == XK_Tab)
		return (1);
	if (keysym == XK_Linefeed)
		return (2);
	if (keysym == XK_Clear)
		return (3);
	if (keysym == XK_Return)
		return (4);
	if (keysym == XK_Pause)
		return (5);
	if (keysym == XK_Scroll_Lock)
		return (6);
	if (keysym == XK_Sys_Req)
		return (7);
	if (keysym == XK_Escape)
		return (8);
	if (keysym == XK_Delete)
		return (9);
	return (-1);
}
