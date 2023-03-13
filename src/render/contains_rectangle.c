/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_rectangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:49:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 15:34:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contains_rectangle.h"

#include "to_fractal_space.h"
#include "libft.h"

bool	contains_fractal(t_s_data *data, t_s_vec2d_d min, int32_t len)
{
	t_s_vec2d_d	max;
	t_s_bounds	*bounds;
	bool		in_x;
	bool		in_y;

	vec2d_copy_d(&max, min);
	max.x += len;
	max.y += len;
	to_fractal_space(data, &min, min, data->view_ratio);
	to_fractal_space(data, &max, max, data->view_ratio);
	min.y = -min.y;
	max.y = -max.y;
	bounds = data->fractal->bounds;
	in_x = ((min.x <= bounds->origin.x)
			&& (max.x >= bounds->origin.x + bounds->width));
	in_y = ((min.y <= -bounds->origin.y)
			&& (max.y >= bounds->height - bounds->origin.y));
	return (in_x && in_y);
}
