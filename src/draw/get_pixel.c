/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:33:40 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/07 17:41:07 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_pixel.h"

#include "mlx.h"
#include <stdint.h>

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

static uint32_t	to_index(t_s_vec2d *vect, uint32_t size_line, uint32_t bpp)
{
	return ((uint32_t)vect->y * size_line + (uint32_t)vect->x * (bpp / 8));
}

char	*get_pixel(t_s_data *data, t_s_vec2d *vect)
{
	static t_s_data_image	*data_image = NULL;
	uint32_t				index;

	if (data == NULL || vect == NULL)
		return (NULL);
	if (data_image == NULL)
		data_image = get_image_data(data);
	index = to_index(vect, data_image->size_line, data_image->bpp);
	return (data_image->data + index);
}
