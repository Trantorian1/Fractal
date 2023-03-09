/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:50:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 14:50:42 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file fractal.c
 * @brief Entry point for fractal display
 *
 * Handles setting up graphics context, fractal data and event hooks used
 * througout the rest of the program.
 */

#include "setup_mlx.h"
#include "setup_hooks.h"
#include "setup_fractal.h"
#include "cleanup.h"
#include "e_fractal.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdint.h>

#ifndef WIDTH
# define WIDTH 1024
#endif

#ifndef HEIGHT
# define HEIGHT 1024
#endif

#define TITLE "Fractal"

int	main(int arc, const char *argv[])
{
	t_s_data	*data;

	(void)arc;
	(void)argv;
	data = setup_mlx(WIDTH, HEIGHT, TITLE);
	if (data == NULL)
		return (EXIT_FAILURE);
	setup_hooks(data);
	setup_fractal(data, TEST);
	mlx_loop(data->mlx);
	cleanup(data);
	return (EXIT_SUCCESS);
}
