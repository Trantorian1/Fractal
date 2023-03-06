/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:42:36 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 16:55:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_mlx.h"

#include "libft.h"
#include "mlx.h"
#include <stdint.h>
#include <stdlib.h>

t_s_data	*setup_mlx(int16_t width, int16_t height, char *title)
{
	void		*mlx;
	void		*main_window;
	t_s_data	*data;

	if (width < 1 || height < 1 || title == NULL)
		return (NULL);
	mlx = mlx_init();
	if (mlx == NULL)
		return (NULL);
	main_window = mlx_new_window(mlx, width, height, title);
	if (main_window == NULL)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (NULL);
	}
	data = ft_malloc(sizeof(*data));
	data->mlx = mlx;
	data->main_window = main_window;
	return (data);
}
