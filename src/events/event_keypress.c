/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:34:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:32:17 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file event_keypress.c
 * @brief Event handler
 */

#include "event_keypress.h"

#include "event_destroy.h"
#include <X11/keysym.h>
#include <stdlib.h>

/**
 * @brief Keypress even hook.
 *
 * Hanldes all key bindings in program.
 * - Esc: closes program
 *
 * @param keysym (int): key symbol.
 * @param data (t_s_data *): global graphics context.
 * @return (int): error code: 0 if no error, 1 otherwise.
 */
int	event_keypress(int keysym, t_s_data *data)
{
	if (keysym == XK_Escape)
		event_destroy(data);
	return (EXIT_SUCCESS);
}
