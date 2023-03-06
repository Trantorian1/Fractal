/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_do_nothing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:50:39 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 16:51:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_do_nothing.h"

#include <stdlib.h>

int	event_do_nothing(t_s_data *data)
{
	(void)data;
	return (EXIT_SUCCESS);
}	
