/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_fractal_increment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:46:16 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 13:56:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file to_fractal_increment.c
 * @brief Space conversion functions.
 */

#include "to_fractal_increment.h"

#include "libft.h"

/**
 * @brief Converts a screen-space increment to fractal-space.
 *
 * @param data (t_s_data *): global graphics context.
 * @param incr_fractal (t_s_vec2d_d *): fractal-space destination.
 * @param incr_screen (t_s_vec2d_d): screen-space source increment.
 * @return (t_s_vec2d_d *): fractal-space increment.
 */
t_s_vec2d_d	*to_fractal_increment(
	t_s_data *data,
	t_s_vec2d_d *incr_fractal,
	t_s_vec2d_d incr_screen)
{
	vec2d_copy_d(incr_fractal, incr_screen);
	vec2d_scale_d(incr_fractal, data->view_ratio);
	incr_fractal->y = -incr_fractal->y;
	return (incr_fractal);
}
