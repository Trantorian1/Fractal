/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_view.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:40:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 18:48:02 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_VIEW_H
# define S_VIEW_H

# include "libft.h"

typedef struct s_view
{
	double		width;
	double		height;
	t_s_vec2d_d	origin;
}	t_s_view;

#endif
