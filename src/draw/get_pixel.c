/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:33:40 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:34:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file get_pixel.c
 * @brief Pixel retrieval functions.
 */

#include "get_pixel.h"

#include "mlx.h"
#include <stdint.h>

typedef struct data_image
{
	int32_t	size_line;
	int32_t	bpp;
	int32_t	endian;
	char	*data;
}	t_s_data_image;

static t_s_data_image	*get_image_data(t_s_data *data)
{
	t_s_data_image	*data_image;

	data_image = ft_malloc(sizeof(*data_image));
	data_image->data = mlx_get_data_addr(
			data->canvas,
			(int32_t *)&data_image->bpp,
			(int32_t *)&data_image->size_line,
			(int32_t *)&data_image->endian);
	return (data_image);
}

static int32_t	to_index(t_s_vec2d_d vect, int32_t size_line, int32_t bpp)
{
	return ((int32_t)vect.y * size_line + (int32_t)vect.x * (bpp / 8));
}

/**
 * @brief Gets the address to a pixel in screen-space.
 *
 * @param data (t_s_data *): global graphics context.
 * @param vect (t_s_vec2d_d *): positon of the pixel in screen-space.
 * @return (char *): pixel address.
 */
char	*get_pixel(t_s_data *data, t_s_vec2d_d vect)
{
	static t_s_data_image	*data_image = NULL;
	int32_t					index;

	if (data == NULL)
		return (NULL);
	if (data_image == NULL)
		data_image = get_image_data(data);
	index = to_index(vect, data_image->size_line, data_image->bpp);
	return (data_image->data + index);
}
