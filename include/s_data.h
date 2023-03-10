/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:20:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 16:41:41 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_DATA_H
# define S_DATA_H

# include "libft.h"
# include "s_view.h"
# include <stdint.h>

typedef struct s_data
{
	double				ratio;
	double				scale;
	double				scale_factor;
	bool				trigger_render;
	t_s_view			view_screen;
	t_s_view			view_fractal;
	struct s_fractal	*fractal;
	void				*mlx;
	void				*main_window;
	void				*canvas;
}	t_s_data;

typedef struct s_fractal
{
	int32_t		max_iter;
	int32_t		bail_bound;
	t_s_view	view_initial;
	double		(*series)(t_s_data *, t_s_vec2d_d);
	int32_t		(*color)(t_s_data *data, double iter);
}	t_s_fractal;

#endif
