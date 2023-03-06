/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:18:11 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 21:13:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paint.h"

#include "libft.h"
#include "mlx.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data_image
{
	uint32_t	size_line;
	uint32_t	bpp;
	uint32_t	endian;
	char		*data;
}	t_s_data_image;

static t_s_data_image	*get_image_data(t_s_data *data)
{
	t_s_data_image	*data_image;

	data_image = ft_malloc(sizeof(*data_image));
	data_image->data = mlx_get_data_addr(
			data->canvas,
			(int *)&data_image->bpp,
			(int *)&data_image->size_line,
			(int *)&data_image->endian);
	return (data_image);
}

static uint32_t	to_index(
	uint32_t x,
	uint32_t y,
	uint32_t size_line,
	uint32_t bpp)
{
	return (y * size_line + x * (bpp / 8));
}	

void	paint(t_s_data *data, t_s_vec2d *vect, int32_t rgb)
{
	static t_s_data_image	*data_image = NULL;
	uint32_t				index;
	char					*pixel;

	if (data_image == NULL)
		data_image = get_image_data(data);
	index = to_index((uint32_t)vect->x, (uint32_t)vect->y,
			data_image->size_line, data_image->bpp);
	pixel = data_image->data + index;
	*(int *)pixel = rgb;
}
