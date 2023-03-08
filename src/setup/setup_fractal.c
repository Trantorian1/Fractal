/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:41:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 18:57:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_fractal.h"

#include "fractal_test.h"
#include "fractal_random.h"

typedef t_s_fractal	*(*t_generator)(void);

static void	setup_view_fractal(t_s_data *data)
{
	double	ratio;

	data->view_fractal.width = data->fractal->view_initial.width;
	ratio = data->view_fractal.width / data->view_screen.width;
	data->view_fractal.height = data->fractal->view_initial.height * ratio;
	data->view_fractal.origin.x = data->fractal->view_initial.origin.x;
	data->view_fractal.origin.y = data->fractal->view_initial.origin.y;
}

void	setup_fractal(t_s_data *data, t_e_fractal type)
{
	static const t_generator	generators[E_FRACTAL_SIZE] = {
		&fractal_test,
		&fractal_random,
		&fractal_test,
		&fractal_test
	};

	if (!data)
		return ;
	data->fractal = generators[type]();
	setup_view_fractal(data);
}
