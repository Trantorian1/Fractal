/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_fractal_coords.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:23:15 by                   #+#    #+#             */
/*   Updated: 2023/03/08 18:23:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_FRACTAL_COORDS_H
# define TO_FRACTAL_COORDS_H

# include "s_data.h"
# include "libft.h"

t_s_vec2d_d	*to_fractal_coords(t_s_data *data, t_s_vec2d_d *screen_coords);

#endif
