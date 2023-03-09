/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:18:11 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 13:05:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paint.h"

#include "get_pixel.h"

void	paint(t_s_data *data, t_s_vec2d_d vect, int32_t rgb)
{
	if (data == NULL)
		return ;
	*(int *)get_pixel(data, vect) = rgb;
}
