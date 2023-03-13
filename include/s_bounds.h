/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_bounds.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:26:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 13:32:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_BOUNDS_H
# define S_BOUNDS_H

# include "libft.h"
# include <stdint.h>

typedef struct s_bounds
{
	double		width;
	double		height;
	t_s_vec2d_d	origin;
}	t_s_bounds;

#endif // !S_BOUNDS_H
