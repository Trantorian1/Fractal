/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_left_arrow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:14:00 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 12:15:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_left_arrow.h"

#include "move.h"
#include "libft.h"

void	handle_left_arrow(t_s_data *data)
{
	static t_s_vec2d_d	direction = {.x = -1.0, .y = 0.0};

	move(data, &direction);
}
