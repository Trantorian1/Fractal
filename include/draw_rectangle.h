/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rectangle.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:12:39 by                   #+#    #+#             */
/*   Updated: 2023/03/08 12:12:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_RECTANGLE_H
# define DRAW_RECTANGLE_H

# include <stdint.h>
# include "s_data.h"

void	draw_rectangle(t_s_data *data, t_s_vec2d *origin, t_s_vec2d *size, int32_t rgb);

#endif
