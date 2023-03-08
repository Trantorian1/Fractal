/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:41:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 15:56:27 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup_fractal.h"

#include "fractal_test.h"
#include "fractal_random.h"

typedef t_s_fractal	*(*t_generator)(void);

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
}
