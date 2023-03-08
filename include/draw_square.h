/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:36:37 by                   #+#    #+#             */
/*   Updated: 2023/03/08 14:36:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SQUARE_H
# define DRAW_SQUARE_H

# include <stdint.h>
# include "s_data.h"

void	draw_square(t_s_data *data, t_s_vec2d *origin, int32_t size, int32_t rgb);

#endif
