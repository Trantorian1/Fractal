/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:42:36 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 18:51:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_mlx.h"

#include "cleanup.h"
#include "event_destroy.h"
#include "libft.h"
#include "mlx.h"
#include <stdint.h>
#include <stdlib.h>

static void	*error_handle(t_s_data *data)
{
	if (data->mlx == NULL)
		return (NULL);
	if (data->canvas)
		mlx_destroy_image(data->mlx, data->canvas);
	if (data->main_window)
		mlx_destroy_window(data->mlx, data->main_window);
	mlx_destroy_display(data->mlx);
	ft_free(data);
	return (NULL);
}

static void	setup_view_screen(t_s_data *data, int16_t width, int16_t height)
{
	data->view_screen.width = width;
	data->view_screen.height = height;
	data->view_screen.origin.x = 0;
	data->view_screen.origin.y = 0;
}

t_s_data	*setup_mlx(int16_t width, int16_t height, char *title)
{
	t_s_data	*data;

	if (width < 1 || height < 1 || title == NULL)
		return (NULL);
	data = ft_malloc(sizeof(*data));
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (error_handle(data));
	data->main_window = mlx_new_window(data->mlx, width, height, title);
	if (data->main_window == NULL)
		return (error_handle(data));
	data->canvas = mlx_new_image(data->mlx, width, height);
	if (data->canvas == NULL)
		return (error_handle(data));
	setup_view_screen(data, width, height);
	return (data);
}
