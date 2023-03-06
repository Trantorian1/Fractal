/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:19:54 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 16:29:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_destroy.h"

#include "mlx.h"
#include <stdlib.h>

int	event_destroy(t_s_data *data)
{
	mlx_destroy_window(data->mlx, data->main_window);
	return (EXIT_SUCCESS);
}
