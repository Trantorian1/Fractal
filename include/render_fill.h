/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fill.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:36:09 by                   #+#    #+#             */
/*   Updated: 2023/03/09 12:37:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_FILL_H
# define RENDER_FILL_H

# include <stdint.h>
# include "s_data.h"

void	render_fill(t_s_data *data, t_s_vec2d_d origin, int32_t len, int32_t color);

#endif
