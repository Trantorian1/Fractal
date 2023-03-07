/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:18:11 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/07 17:41:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paint.h"

#include "get_pixel.h"

void	paint(t_s_data *data, t_s_vec2d *vect, int32_t rgb)
{
	if (data == NULL || vect == NULL)
		return ;
	*(int *)get_pixel(data, vect) = rgb;
}
