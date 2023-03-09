/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:52:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 14:20:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
