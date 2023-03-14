/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:41:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 15:27:45 by emcnab           ###   ########.fr       */
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

static void	center_fractal(t_s_data *data, t_s_fractal *fractal)
{
	t_s_bounds	*bounds;
	t_s_vec2d_d	view;
	double		ratio;
	t_s_vec2d_d	in_fractal;
	t_s_vec2d_d	centered;

	bounds = fractal->bounds;
	view.x = data->view_screen->width - 2 * data->view_padding;
	view.y = view.x * bounds->height / bounds->width;
	ratio = bounds->width / view.x;
	in_fractal.x = data->view_screen->width * ratio;
	in_fractal.y = data->view_screen->height * ratio;
	centered.x = bounds->origin.x - (in_fractal.x - bounds->width) / 2;
	centered.y = bounds->origin.y + (in_fractal.y - bounds->height) / 2;
	fractal->view_initial = ft_malloc(sizeof(*fractal->view_initial));
	fractal->view_initial->width = in_fractal.x;
	fractal->view_initial->height = in_fractal.y;
	vec2d_copy_d(&fractal->view_initial->origin, &centered);
}

static void	setup_view_fractal(t_s_data *data, t_s_fractal *fractal)
{
	double	ratio;

	data->view_fractal = ft_malloc(sizeof(*data->view_fractal));
	data->view_fractal->width = fractal->view_initial->width;
	ratio = data->view_fractal->width / data->view_screen->width;
	data->view_fractal->height = fractal->view_initial->height * ratio;
	data->view_fractal->origin.x = fractal->view_initial->origin.x;
	data->view_fractal->origin.y = fractal->view_initial->origin.y;
	data->view_ratio = ratio;
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
		NULL,
		NULL,
		&mandelbroot,
		NULL
	};

	if (!data)
		return ;
	data->fractal = generators[type]();
	data->fractal->max_iter = data->fractal->max_iter_initial;
	center_fractal(data, data->fractal);
	setup_view_fractal(data, data->fractal);
	data->debug = false;
	data->trigger_render = true;
}
