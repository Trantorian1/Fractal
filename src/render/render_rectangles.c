/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rectangles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:25:47 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/07 19:33:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_rectangles.h"

#include "paint.h"
#include <stdlib.h>

static int32_t	trace_edge(
	t_s_data *data,
	t_s_vec2d *start,
	t_s_vec2d *increment,
	int32_t l)
{
	int32_t		bail_prev;
	int32_t		bail_curr;
	t_s_vec2d	end;

	end.x = start->x + increment->x * l;
	end.y = start->y + increment->y * l;
	bail_prev = data->fractal->color(data->fractal->series(data, start));
	bail_curr = data->fractal->color(data->fractal->series(data, &end));

}

static void	recursive_pass(t_s_data *data, t_s_vec2d *origin, int32_t size)
{
	size_t	i;
}

// void	render_rectangles(t_s_data *data, t_s_symetry *symmetry)
void	render_rectangles(t_s_data *data)
{
	if (data == NULL)
		return ;
}
