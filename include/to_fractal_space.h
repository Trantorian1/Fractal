/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_fractal_space.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:15:49 by                   #+#    #+#             */
/*   Updated: 2023/03/09 16:16:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_FRACTAL_SPACE_H
# define TO_FRACTAL_SPACE_H

# include "s_data.h"
# include "libft.h"

t_s_vec2d_d	*to_fractal_space(
	t_s_data *data,
	t_s_vec2d_d *dest,
	t_s_vec2d_d source,
	double ratio);

#endif
