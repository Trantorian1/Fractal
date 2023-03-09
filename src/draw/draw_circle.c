/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:45:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 13:15:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_circle.h"

#include "mlx.h"
#include "paint.h"
#include "libft.h"
#include <stddef.h>
#include <stdbool.h>

static bool	is_in_circle(t_s_vec2d *vect, int32_t r)
{
	return (vect->x * vect->x + vect->y * vect->y <= r * r);
}

void	draw_circle(t_s_data *data, t_s_vec2d *origin, int32_t r, int32_t rgb)
{
	t_s_vec2d	vect;
	t_s_vec2d	in_canvas;

	(void)data;
	(void)rgb;
	vect.x = -r;
	while (vect.x < r)
	{
		vect.y = -r;
		while (vect.y < r)
		{
			if (is_in_circle(&vect, r))
			{
				in_canvas.x = origin->x + vect.x;
				in_canvas.y = origin->y + vect.y;
				// paint(data, in_canvas, rgb);
			}
			vect.y++;
		}
		vect.x++;
	}
}
