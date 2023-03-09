/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:18:11 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:38:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file paint.c
 * @brief Pixel writing functions.
 */

#include "paint.h"

#include "get_pixel.h"

/**
 * @brief Paints a pixel onto global canvas.
 *
 * @param data (t_s_data *): global graphics context.
 * @param vect (t_s_vec2d_d): pixel coordinates in screen-space.
 * @param rgb (int32_t): pixel color.
 *
 * @warning Pixel will not be draw to screen till mlx_put_image_to_window is
 * called as part of renderer. This ensures that all pixels are displayed at the
 * same time and that only one screem refresh is needed.
 */
void	paint(t_s_data *data, t_s_vec2d_d vect, int32_t rgb)
{
	if (data == NULL)
		return ;
	*(int *)get_pixel(data, vect) = rgb;
}
