/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:00:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:44:29 by emcnab           ###   ########.fr       */
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
 */
void	renderer(t_s_data *data)
{
	if (data->main_window == NULL)
		return ;
	render_rectangles(data);
	data->trigger_render = false;
	mlx_put_image_to_window(data->mlx, data->main_window, data->canvas, 0, 0);
}
