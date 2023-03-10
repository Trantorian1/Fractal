/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:41:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/13 18:35:29 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_mouse_move.h"

#include "panning.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	event_mouse_move(int x, int y, t_s_data *data)
{
	if (data->panning->is_panning)
		panning(x, y, data);
	return (EXIT_SUCCESS);
}
