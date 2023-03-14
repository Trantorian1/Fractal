/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:19:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 11:49:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyrelease.h"

#include "normalise_key_function.h"
#include "is_key_alpha.h"
#include "is_key_function.h"
#include "is_key_modifier.h"
#include "is_key_motion.h"
#include <stdint.h>
#include <X11/keysym.h>
#include <stdio.h>

static const int64_t	g_delta_func = XK_Z - XK_A;
static const int64_t	g_delta_motion = g_delta_func + 10;

static void	release_letter_key(t_s_data *data, int keysym)
{
	t_s_keys	*keys;
	int64_t		mask;

	printf("here\n");
	keys = data->keys;
	mask = 1 << (keysym - XK_A);
	keys->pressed &= ~mask;
	keys->released |= mask;
}

static void	release_function_key(t_s_data *data, int keysym)
{
	t_s_keys				*keys;
	int64_t					mask;

	keys = data->keys;
	mask = 1 << (normalise_key_func(keysym) + g_delta_func);
	keys->pressed &= ~mask;
	keys->released |= mask;
}

static void	release_motion_key(t_s_data *data, int keysym)
{
	t_s_keys	*keys;
	int64_t		mask;

	keys = data->keys;
	mask = 1 << (keysym - XK_Home + g_delta_motion);
	keys->pressed &= ~mask;
	keys->released |= mask;
}

static void	release_modifier_key(t_s_data *data, int keysym)
{
	t_s_keys	*keys;
	int64_t		mask;

	keys = data->keys;
	mask = 1 << (keysym - XK_Shift_L);
	keys->modifiers &= ~mask;
}

void	keyrelease(t_s_data *data, int keysym)
{
	if (is_key_alpha(keysym))
		release_letter_key(data, keysym);
	else if (is_key_function(keysym))
		release_function_key(data, keysym);
	else if (is_key_motion(keysym))
		release_motion_key(data, keysym);
	else if (is_key_modifier(keysym))
		release_modifier_key(data, keysym);
}
