/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 19:58:08 by                   #+#    #+#             */
/*   Updated: 2023/03/06 20:15:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_CIRCLE_H
# define DRAW_CIRCLE_H

# include <stdint.h>
# include "s_data.h"
#include "libft.h"

void	draw_circle(t_s_data *data, t_s_vec2d *origin, int32_t r, int32_t rgb);

#endif
