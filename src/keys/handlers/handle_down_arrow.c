/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_down_arrow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:59:20 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 13:00:31 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_down_arrow.h"

#include "move.h"
#include "libft.h"

void	handle_down_arrow(t_s_data *data)
{
	static t_s_vec2d_d	direction = {.x = 0.0, .y = -1.0};

	move(data, &direction);
}
