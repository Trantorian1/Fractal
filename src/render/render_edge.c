/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_edge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:49:55 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 13:56:19 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file render_edge.c
 * @brief Edge rendering functions in use in render_rectangles. 
 */

#include "render_edge.h"

#include "is_in_screen.h"
#include "paint.h"
#include "to_fractal_space.h"
#include "to_fractal_increment.h"
#include "calculate_bail.h"
#include <stdio.h>

static void	increment(
	t_s_vec2d_d *in_screen,
	t_s_vec2d_d incr_screen,
	t_s_vec2d_d *in_fractal,
	t_s_vec2d_d incr_fractal)
{
	vec2d_add_d(in_screen, incr_screen);
	vec2d_add_d(in_fractal, incr_fractal);
}

static int32_t	drawn(t_s_vec2d_d start, t_s_vec2d_d end)
{
	int32_t	dx;
	int32_t	dy;

	dx = abs((int32_t)(end.x - start.x));
	dy = abs((int32_t)(end.y - start.y));
	return (max(dx, dy));
}

/**
 * @brief Renders the edge of a rectangle accoring to the fractal series
 * specified in graphics context.
 *
 * Keeps rendering pixels as long as they share the same neighbouring bail. As
 * soon as a discontinuity is detected, exits function.
 *
 * @param data (t_s_data *): global graphics context.
 * @param start_screen (t_s_vec2d_d): edge origin.
 * @param incr_screen (t_s_vec2d_d): screen-space pixel increment.
 * @param len (int32_t): edge length.
 * @return (int32_t): number of pixels rendered before a discontinuity in bail
 * was detected.
 */
int32_t	render_edge(
	t_s_data *data,
	t_s_vec2d_d start_screen,
	t_s_vec2d_d incr_screen,
	int32_t len)
{
	t_s_vec2d_d	in_screen;
	t_s_vec2d_d	in_fractal;
	t_s_vec2d_d	incr_fractal;
	int32_t		bail_prev;
	int32_t		bail_curr;

	vec2d_copy_d(&in_screen, start_screen);
	to_fractal_increment(data, &incr_fractal, incr_screen);
	to_fractal_space(data, &in_fractal, start_screen, data->view_ratio);
	bail_prev = calculate_bail(data, in_fractal, in_screen);
	increment(&in_screen, incr_screen, &in_fractal, incr_fractal);
	bail_curr = calculate_bail(data, in_fractal, in_screen);
	while (is_in_screen(data, &in_screen)
		&& bail_prev == bail_curr
		&& drawn(start_screen, in_screen) < len)
	{
		increment(&in_screen, incr_screen, &in_fractal, incr_fractal);
		bail_prev = bail_curr;
		bail_curr = calculate_bail(data, in_fractal, in_screen);
	}
	return (drawn(start_screen, in_screen));
}
