/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:35:48 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 14:38:17 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_square.h"

#include "draw_rectangle.h"

void	draw_square(
	t_s_data *data,
	t_s_vec2d *origin,
	int32_t size,
	int32_t rgb)
{
	t_s_vec2d	dimensions;

	dimensions.x = size;
	dimensions.y = size;
	draw_rectangle(data, origin, &dimensions, rgb);
}
