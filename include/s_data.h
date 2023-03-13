/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:20:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 16:00:03 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DATA_H
# define S_DATA_H

# include "libft.h"
# include "s_view.h"
# include "s_bounds.h"
# include <stdint.h>

typedef struct s_data
{
	bool				trigger_render;
	double				scale_factor;
	double				view_ratio;
	double				view_padding;
	t_s_view			*view_screen;
	t_s_view			*view_fractal;
	struct s_fractal	*fractal;
	void				*mlx;
	void				*main_window;
	void				*canvas;
}	t_s_data;

typedef struct s_fractal
{
	int32_t		max_iter;
	int32_t		bail_bound;
	t_s_view	*view_initial;
	t_s_bounds	*bounds;
	double		(*series)(t_s_data *, t_s_vec2d_d*);
	int32_t		(*color)(t_s_data *data, double iter);
}	t_s_fractal;

#endif
