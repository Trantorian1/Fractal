/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:17:29 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:23:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "increase_iter.h"

#define ITER_MAX 1000

void	increase_iter(t_s_data *data)
{
	if (data->fractal->max_iter >= ITER_MAX)
		return ;
	data->fractal->max_iter += data->fractal->delta_iter;
	data->trigger_render = true;
}
