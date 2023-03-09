/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_fractal_increment.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:47:36 by                   #+#    #+#             */
/*   Updated: 2023/03/09 16:48:06 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_FRACTAL_INCREMENT_H
# define TO_FRACTAL_INCREMENT_H

# include "s_data.h"
# include "libft.h"

t_s_vec2d_d	*to_fractal_increment(
	t_s_data *data,
	t_s_vec2d_d *incr_fractal,
	t_s_vec2d_d incr_screen);

#endif
