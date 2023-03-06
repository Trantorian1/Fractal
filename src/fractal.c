/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:52:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 15:02:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdint.h>

#define TITLE "Fractal"

static int	do_nothing(void)
{
}

int	main(int arc, const char *argv[])
{
	void	*mlx;
	void	*main_window;
	int32_t	max_width;
	int32_t	max_height;

	(void)arc;
	(void)argv;
	mlx = mlx_init();
	if (!mlx)
		return (EXIT_FAILURE);
	mlx_get_screen_size(mlx, &max_width, &max_height);
	main_window = mlx_new_window(mlx, max_width, max_height, TITLE);
	if (!main_window)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (EXIT_FAILURE);
	}

	mlx_loop_hook(mlx, &do_nothing, NULL);

	mlx_loop(mlx);

	mlx_destroy_window(mlx, main_window);
	mlx_destroy_display(mlx);
	free(mlx);
	return (EXIT_SUCCESS);
}
