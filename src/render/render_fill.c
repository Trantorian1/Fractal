/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:21:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 12:49:16 by emcnab           ###   ########.fr       */
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

	vec2d_copy_d(&in_screen, origin);
	while ((in_screen.x - origin.x) < len)
	{
		while ((in_screen.y - origin.y) < len)
		{
			paint(data, in_screen, color);
			in_screen.y++;
		}
		in_screen.x++;
	}
}
