/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:21:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 14:08:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_fill.h"

#include "paint.h"
#include "libft.h"

void	render_fill(
	t_s_data *data,
	t_s_vec2d_d origin,
	int32_t len,
	int32_t color)
{
	t_s_vec2d_d	in_screen;

	in_screen.x = origin.x;
	while ((in_screen.x - origin.x) < len)
	{
		in_screen.y = origin.y;
		while ((in_screen.y - origin.y) < len)
		{
			paint(data, in_screen, color);
			in_screen.y++;
		}
		in_screen.x++;
	}
}
