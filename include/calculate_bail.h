/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_bail.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:12:34 by                   #+#    #+#             */
/*   Updated: 2023/03/13 15:59:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATE_BAIL_H
# define CALCULATE_BAIL_H

# include <stdint.h>
# include "s_data.h"

int32_t	calculate_bail(
	t_s_data *data,
	t_s_vec2d_d *in_fractal,
	t_s_vec2d_d *in_screen);

#endif
