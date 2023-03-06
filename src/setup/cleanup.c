/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:54:24 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 16:57:05 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

void	cleanup(t_s_data *data)
{
	if (data == NULL)
		return ;
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free_all();
}
