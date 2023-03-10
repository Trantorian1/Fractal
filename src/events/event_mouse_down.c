/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_down.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:28:23 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 12:48:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_down.h"

#include "event_mouse_scrolldown.h"
#include "event_mouse_scrollup.h"
#include "e_mouse_event.h"
#include <stdlib.h>

typedef int	(*t_mouse_event)(int, int, int, t_s_data *);

int	event_mouse_down(int32_t button, int32_t x, int32_t y, t_s_data *data)
{
	static t_mouse_event	events[E_MOUSE_EVENT_SIZE]
		= {
		NULL,
		NULL,
		NULL,
		NULL,
		&event_mouse_scrollup,
		&event_mouse_scrolldown};

	events[button](button, x, y, data);
	return (EXIT_SUCCESS);
}
