/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_rectangle.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:50:41 by                   #+#    #+#             */
/*   Updated: 2023/03/13 13:50:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINS_RECTANGLE_H
# define CONTAINS_RECTANGLE_H

# include <stdbool.h>
# include <stdint.h>
# include "s_data.h"

bool	contains_fractal(t_s_data *data, t_s_vec2d_d min, int32_t len);

#endif
