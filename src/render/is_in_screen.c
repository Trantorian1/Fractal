/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:52:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 13:55:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_in_screen.h"
#include <stdio.h>

bool	is_in_screen(t_s_data *data, t_s_vec2d_d *point)
{
	const t_s_view	*screen = data->view_screen;
	const bool		is_in_x = point->x >= screen->origin.x
		&& point->x <= screen->origin.x + screen->width;
	const bool		is_in_y = point->y >= screen->origin.y
		&& point->y <= screen->origin.y + screen->height;

	return (is_in_x && is_in_y);
}
