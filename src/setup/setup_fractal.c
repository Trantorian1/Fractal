/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:41:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 13:39:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file setup_fractal.c
 * @brief Handles selecting and saving fractal data used to calculate and
 * display fractal.
 */

#include "setup_fractal.h"

#include "fractal_test.h"
#include "fractal_random.h"
#include "mandelbroot.h"

typedef t_s_fractal	*(*t_generator)(void);

static void	setup_view_fractal(t_s_data *data)
{
	double	ratio;

	data->view_fractal.width = data->fractal->view_initial.width;
	ratio = data->view_fractal.width / data->view_screen.width;
	data->view_fractal.height = data->fractal->view_initial.height * ratio;
	data->view_fractal.origin.x = data->fractal->view_initial.origin.x;
	data->view_fractal.origin.y = data->fractal->view_initial.origin.y;
	data->ratio = ratio;
}

/**
 * @brief Selects and saves fractal data as part of global graphics context.
 *
 * Saved fractal data includes:
 * - fractal series
 * - fractal color generation
 * - fractal viewport
 * - fractal-space to screen-space ratio
 *
 * @param data (t_s_data *): global graphics context.
 * @param type (t_e_fractal): fractal type to get the data for (ex: MANDELBROOT)
 */
void	setup_fractal(t_s_data *data, t_e_fractal type)
{
	static const t_generator	generators[E_FRACTAL_SIZE] = {
		&fractal_test,
		&fractal_random,
		&mandelbroot,
		&fractal_test
	};

	if (!data)
		return ;
	data->fractal = generators[type]();
	setup_view_fractal(data);
	data->scale = 1.0;
	data->scale_factor = 0.95;
	data->trigger_render = true;
}
