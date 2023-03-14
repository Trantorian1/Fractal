/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_released.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:02:30 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:07:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_key_released.h"

#include "is_key_alpha.h"
#include "is_key_function.h"
#include <X11/keysym.h>
#include <stdint.h>

static int64_t	is_key_letter_pressed(t_s_data *data, int keysym)
{
	t_s_keys	*keys;
	int64_t		mask;

	keys = data->keys;
	mask = 1 << (keysym - XK_A);
	return ((keys->pressed & mask) > 0 * mask);
}

static int64_t	is_key_function_released(t_s_data *data, int keysym)
{
	t_s_keys				*keys;
	int64_t					mask;
	static const int64_t	delta = XK_Z - XK_A;

	keys = data->keys;
	mask = 1 << (keysym - XK_BackSpace + delta);
	return ((keys->pressed & mask) > 0 * mask);
}

int64_t	is_key_released(t_s_data *data, int keysym)
{
	if (is_key_alpha(keysym))
		return (is_key_letter_pressed(data, keysym));
	else if (is_key_function(keysym))
		return (is_key_function_released(data, keysym));
	return (0x0);
}
