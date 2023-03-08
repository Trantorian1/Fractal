/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_screen_coords.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:04:29 by                   #+#    #+#             */
/*   Updated: 2023/03/08 18:21:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_SCREEN_COORDS_H
# define TO_SCREEN_COORDS_H

# include "s_data.h"
# include "libft.h"

t_s_vec2d_d	*to_screen_coords(t_s_data *data, t_s_vec2d_d *fractal_coords);

#endif
