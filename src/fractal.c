/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:52:56 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 17:15:50 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_mlx.h"
#include "setup_hooks.h"
#include "cleanup.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 1000
#define HEIGHT 1000
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
	mlx_loop(data->mlx);
	cleanup(data);
	return (EXIT_SUCCESS);
}