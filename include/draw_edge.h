/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edge.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:52:44 by                   #+#    #+#             */
/*   Updated: 2023/03/09 11:31:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_EDGE_H
# define DRAW_EDGE_H

# include <stddef.h>
# include <stdint.h>
# include "s_data.h"

int32_t	draw_edge(
	t_s_data *data,
	t_s_vec2d_d start,
	t_s_vec2d_d incr_screen,
	double len);

#endif
