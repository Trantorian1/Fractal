/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_view.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:44:28 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/08 18:49:20 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_view.h"

#include "libft.h"

t_s_vec2d_d	*to_view(t_s_view view_old, t_s_view view_new, t_s_vec2d_d vect)
{
	double		ratio;

	ratio = view_new.width / view_old.width;
	return (vec2d_new_d(vect.x * ratio, vect.y * ratio));
}
