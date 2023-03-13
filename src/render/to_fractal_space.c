/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_fractal_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:15:18 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 13:56:59 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file to_fractal_space.c
 * @brief Space conversion functions
 */

#include "to_fractal_space.h"

/**
 * @brief Converst a screen-space vector to fractal-space.
 *
 * @param data (t_s_data *): global graphics constext.
 * @param dest (t_s_vec2d_d *): destination fractal-space vector.
 * @param source (t_s_vec2d_d *): screen-space source vector.
 * @param ratio (double): fractal-space to screen-space ratio.
 * @return (t_s_vec2d_d *): fractal-space vector.
 */
t_s_vec2d_d	*to_fractal_space(
	t_s_data *data,
	t_s_vec2d_d *dest,
	t_s_vec2d_d source,
	double ratio)
{
	vec2d_copy_d(dest, source);
	vec2d_scale_d(dest, ratio);
	dest->y = -dest->y;
	vec2d_add_d(dest, data->view_fractal->origin);
	return (dest);
}
