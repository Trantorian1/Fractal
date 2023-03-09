/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:54:24 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:05:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file cleanup.c
 * @brief Memory freeing functions
 */

#include "cleanup.h"

#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

/**
 * @brief Cleans up memory allocated during setup.
 *
 * @param data (t_s_data *): global graphics context.
 */
void	cleanup(t_s_data *data)
{
	if (data == NULL)
		return ;
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_all();
}
