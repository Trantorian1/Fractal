/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_scrolldown.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:33:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 12:45:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_scrolldown.h"

#include <stdio.h>
#include <stdlib.h>

int	event_mouse_scrolldown(int32_t button, int32_t x, int32_t y, t_s_data *data)
{
	(void)button;
	(void)x;
	(void)y;
	(void)data;
	printf("Scrolling Down!\n");
	return (EXIT_SUCCESS);
}
