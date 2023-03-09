/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_bail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:11:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 18:22:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file calculate_bail.c
 * @brief Bail calcultions functions.
 */

#include "calculate_bail.h"

#include "paint.h"

/**
 * @brief Calculates fractal bail at a given point in fractal-space.
 *
 * Once the bail is calculated it is hashed into a color and stored in the
 * global canvas texture. This allows to minimise bail calcultiions by sampling
 * previous bail results from the texture.
 *
 * @param data (t_s_data *): global graphics context.
 * @param in_fractal (t_s_vec2d_d *): coordinates in fractal space.
 * @param in_screen (t_s_vec2d_d *): coordinates in in screen space.
 * @return (int32_t): fractal bail at coordinates in fractal space.
 */
int32_t	calculate_bail(
	t_s_data *data,
	t_s_vec2d_d in_fractal,
	t_s_vec2d_d in_screen)
{
	int32_t	bail;

	bail = data->fractal->color(data->fractal->series(data, in_fractal));
	paint(data, in_screen, bail);
	return (bail);
}
