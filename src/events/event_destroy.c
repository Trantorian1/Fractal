/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:19:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:28:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file event_destroy.c
 * @brief Event hooks
 */

#include "event_destroy.h"

#include "mlx.h"
#include <stdlib.h>

/**
 * @brief Window destruction event handler.
 *
 * Frees up memory allocated by the graphics library and sets graphics pointers
 * to NULL, which will stop the rendering loop.
 *
 * @param data (t_s_data *) global rendering context.
 * @return (int): error code: 0 if no error, 1 otherwise.
 */
int	event_destroy(t_s_data *data)
{
	mlx_destroy_image(data->mlx, data->canvas);
	mlx_destroy_window(data->mlx, data->main_window);
	data->canvas = NULL;
	data->main_window = NULL;
	return (EXIT_SUCCESS);
}
