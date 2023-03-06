/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keypress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:34:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/06 16:40:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event_keypress.h"

#include "event_destroy.h"
#include <X11/keysym.h>
#include <stdlib.h>

int	event_keypress(int keysym, t_s_data *data)
{
	if (keysym == XK_Escape)
		event_destroy(data);
	return (EXIT_SUCCESS);
}
