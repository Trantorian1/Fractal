/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_do_nothing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:11:15 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 17:53:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_do_nothing.h"

#include <stdlib.h>

int	event_mouse_do_nothing(int32_t button, int32_t x, int32_t y, t_s_data *data)
{
	(void)button;
	(void)x;
	(void)y;
	(void)data;
	return (EXIT_SUCCESS);
}
