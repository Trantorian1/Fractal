/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keyrelease.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:13:08 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:14:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_keyrelease.h"

#include "keyrelease.h"
#include <stdlib.h>

int	event_keyrelease(int keysym, t_s_data *data)
{
	keyrelease(data, keysym);
	return (EXIT_SUCCESS);
}
