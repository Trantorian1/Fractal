/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:11:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 14:35:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_rectangle.h"

#include "paint.h"

void	draw_rectangle(
	t_s_data *data,
	t_s_vec2d *origin,
	t_s_vec2d *size,
	int32_t rgb)
{
	t_s_vec2d	cursor;

	cursor.x = origin->x;
	while (cursor.x - origin->x < size->x)
	{
		cursor.y = origin->y;
		while (cursor.y - origin->y < size->y)
		{
			paint(data, &cursor, rgb);
			cursor.y++;
		}
		cursor.x++;
	}
}
