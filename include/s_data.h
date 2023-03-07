/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:20:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/07 19:19:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DATA_H
# define S_DATA_H

# include "libft.h"
# include <stdint.h>

typedef struct s_data
{
	int32_t				width;
	int32_t				height;
	struct s_fractal	*fractal;
	void				*mlx;
	void				*main_window;
	void				*canvas;
}	t_s_data;

typedef struct s_fractal
{
	int32_t	(*series)(t_s_data *, t_s_vec2d *);
	int32_t	(*color)(int32_t rgb);
}	t_s_fractal;

#endif
