/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:21:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:44:44 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file render_fill.c
 * @brief Rendering functions used in render_rectangles.c
 */

#include "render_fill.h"

#include "paint.h"
#include "libft.h"

/**
 * @brief Fills in a square in scren-space with a singular color.
 *
 * @param data (t_s_data *): global graphics context.
 * @param origin (t_s_vec2d_d): square origin.
 * @param len (int32_t): square widht.
 * @param color (int32_t): rgb color code used to fill square.
 */
void	render_fill(
	t_s_data *data,
	t_s_vec2d_d origin,
	int32_t len,
	int32_t color)
{
	t_s_vec2d_d	in_screen;

	in_screen.x = origin.x;
	while ((in_screen.x - origin.x) < len)
	{
		in_screen.y = origin.y;
		while ((in_screen.y - origin.y) < len)
		{
			paint(data, in_screen, color);
			in_screen.y++;
		}
		in_screen.x++;
	}
}
