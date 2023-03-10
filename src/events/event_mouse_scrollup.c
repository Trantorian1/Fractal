/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_scrollup.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:31:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 12:44:48 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_scrollup.h"

#include <stdio.h>
#include <stdlib.h>

int	event_mouse_scrollup(int32_t button, int32_t x, int32_t y, t_s_data *data)
{
	(void)button;
	(void)x;
	(void)y;
	(void)data;
	printf("Scrolling Up!\n");
	return (EXIT_SUCCESS);
}
