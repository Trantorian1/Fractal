/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:20:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 09:46:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DATA_H
# define S_DATA_H

# include "libft.h"
#include "e_states.h"
# include "s_view.h"
# include "s_bounds.h"
# include <stdint.h>

typedef struct s_data
{
	bool				trigger_render;
	double				view_ratio;
	double				view_padding;
	void				*mlx;
	void				*main_window;
	void				*canvas;
	struct s_zoom		*zoom;
	struct s_panning	*panning;
	struct s_keys		*keys;
	t_s_view			*view_screen;
	t_s_view			*view_fractal;
	struct s_fractal	*fractal;
}	t_s_data;

typedef struct s_zoom
{
	double	zoom_factor;
	double	zoom_scale;
	int32_t	zoom_count;
}	t_s_zoom;

typedef struct s_panning
{
	bool		is_panning;
	t_s_vec2d_d	last_pos;
}	t_s_panning;

typedef struct s_keys
{
	int64_t	pressed;
	int64_t	released;
	int32_t	modifiers;
}	t_s_keys;

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
