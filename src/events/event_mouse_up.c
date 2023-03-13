/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:32:37 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 17:39:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_up.h"

#include "event_mouse_do_nothing.h"
#include "event_mouse_left_release.h"
#include "e_mouse_event.h"
#include <stdlib.h>

typedef int	(*t_mouse_event)(int, int, int, t_s_data *);

int	event_mouse_up(int32_t button, int32_t x, int32_t y, t_s_data *data)
{
	static t_mouse_event	events[E_MOUSE_EVENT_SIZE]
		= {&event_mouse_do_nothing,
		&event_mouse_left_release,
		&event_mouse_do_nothing,
		&event_mouse_do_nothing,
		&event_mouse_do_nothing,
		&event_mouse_do_nothing};

	events[button](button, x, y, data);
	return (EXIT_SUCCESS);
}
