/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:35:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 11:42:11 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_key_pressed.h"

#include "normalise_key_function.h"
#include "is_key_alpha.h"
#include "is_key_function.h"
#include "is_key_motion.h"
#include <X11/keysym.h>
#include <stdint.h>
#include <stdio.h>

static const int64_t	g_delta_func = XK_Z - XK_A;
static const int64_t	g_delta_motion = g_delta_func + 10;

static int64_t	is_key_letter_pressed(t_s_data *data, int keysym)
{
	t_s_keys	*keys;
	int64_t		mask;

	keys = data->keys;
	mask = 1 << (keysym - XK_A);
	return ((keys->pressed & mask) > 0 * mask);
}

static int64_t	is_key_function_pressed(t_s_data *data, int keysym)
{
	t_s_keys				*keys;
	int64_t					mask;

	keys = data->keys;
	mask = 1 << (normalise_key_func(keysym) + g_delta_func);
	return ((keys->pressed & mask) > 0 * mask);
}

static int64_t	is_key_motion_pressed(t_s_data *data, int keysym)
{
	t_s_keys	*keys;
	int64_t		mask;

	keys = data->keys;
	mask = 1 << (keysym - XK_Home + g_delta_motion);
	return ((keys->pressed & mask) > 0 * mask);
}

int64_t	is_key_pressed(t_s_data *data, int keysym)
{
	if (is_key_alpha(keysym))
		return (is_key_letter_pressed(data, keysym));
	else if (is_key_function(keysym))
		return (is_key_function_pressed(data, keysym));
	else if (is_key_motion(keysym))
		return (is_key_motion_pressed(data, keysym));
	return (0x0);
}
