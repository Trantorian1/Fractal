/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_fractal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:49:43 by                   #+#    #+#             */
/*   Updated: 2023/03/13 15:49:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINS_FRACTAL_H
# define CONTAINS_FRACTAL_H

# include <stdbool.h>
# include <stdint.h>
# include "s_data.h"

bool	contains_fractal(t_s_data *data, t_s_vec2d_d *origin, int32_t len);

#endif
