/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:00:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 21:13:55 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"

#include "draw_circle.h"
#include "mlx.h"
#include <stdlib.h>

int	renderer(t_s_data *data)
{
	static t_s_vec2d	origin = {500, 500};

	if (data->main_window == NULL)
		return (EXIT_FAILURE);
	draw_circle(data, &origin, 200, 0xFF0000);
	mlx_put_image_to_window(data->mlx, data->main_window, data->canvas, 0, 0);
	return (EXIT_SUCCESS);
}
