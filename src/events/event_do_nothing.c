/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_do_nothing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:50:39 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:30:00 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file event_do_nothing.c
 * @brief Event handlers
 */

#include "event_do_nothing.h"

#include <stdlib.h>

/**
 * @brief Placeholder event which does nothing.
 *
 * @param data (t_s_data *): global graphics context.
 * @return (int): error code: 0 if no error, 1 otherwise.
 */
int	event_do_nothing(t_s_data *data)
{
	(void)data;
	return (EXIT_SUCCESS);
}	
