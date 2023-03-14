/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrease_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:14:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:24:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decrease_iter.h"

#define ITER_MIN 100

void	decrease_iter(t_s_data *data)
{
	if (data->fractal->max_iter <= ITER_MIN)
		return ;
	data->fractal->max_iter -= data->fractal->delta_iter;
	data->trigger_render = true;
}
