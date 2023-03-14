/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:00:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:34:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file renderer.c
 * @brief Rendering functions.
 */

#include "renderer.h"

#include "fractal_keymap.h"
#include "render_rectangles.h"
#include "mlx.h"
#include <stdlib.h>

/**
 * @brief Main fractal renderer. Handles image generation and display.
 *
 * @param data (t_s_data *): global graphics context.
 * @return (int): error code: 0 if no error, 1 otherwise.
 */
int	renderer(t_s_data *data)
{
	fractal_keymap(data);
	if (data->main_window == NULL)
		return (EXIT_FAILURE);
	if (data->trigger_render == true)
	{
		render_rectangles(data);
		data->trigger_render = false;
	}
	mlx_put_image_to_window(data->mlx, data->main_window, data->canvas, 0, 0);
	return (EXIT_SUCCESS);
}
