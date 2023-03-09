/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:00:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:07:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file renderer.c
 * @brief Rendering functions.
 */

#include "renderer.h"

#include "draw_circle.h"
#include "render_rectangles.h"
#include "mlx.h"
#include <stdlib.h>

#if 0

int	renderer(t_s_data *data)
{
	static t_s_vec2d	origin = {500, 500};

	if (data->main_window == NULL)
		return (EXIT_FAILURE);
	draw_circle(data, &origin, 200, 0xFF0000);
	mlx_put_image_to_window(data->mlx, data->main_window, data->canvas, 0, 0);
	return (EXIT_SUCCESS);
}
#else

/**
 * @brief Main fractal renderer. Handles image generation and display.
 *
 * @param data (t_s_data *): global graphics context.
 * @return (int): error code: 0 if no error, 1 otherwise.
 */
int	renderer(t_s_data *data)
{
	if (data->main_window == NULL)
		return (EXIT_FAILURE);
	render_rectangles(data);
	mlx_put_image_to_window(data->mlx, data->main_window, data->canvas, 0, 0);
	return (EXIT_SUCCESS);
}

#endif
