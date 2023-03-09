/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_edge.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:51:30 by                   #+#    #+#             */
/*   Updated: 2023/03/09 12:43:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_EDGE_H
# define RENDER_EDGE_H

# include <stdint.h>
# include "s_data.h"

int32_t	render_edge(
	t_s_data *data,
	t_s_vec2d_d start,
	t_s_vec2d_d incr_screen);

#endif
