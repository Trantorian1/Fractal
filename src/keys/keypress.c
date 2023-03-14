/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:29:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 09:53:43 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keypress.h"

#include "is_key_alpha.h"
#include "is_key_function.h"
#include "is_key_modifier.h"
#include <stdint.h>
#include <X11/keysym.h>

static void	store_letter_key(t_s_data *data, int keysym)
{
	t_s_keys	*keys;
	int64_t		mask;

	keys = data->keys;
	mask = 1 << (keysym - XK_A);
	keys->pressed |= mask;
	keys->released &= ~mask;
}

static void	store_function_key(t_s_data *data, int keysym)
{
	t_s_keys				*keys;
	int64_t					mask;
	static const int64_t	delta = XK_Z - XK_A;

	keys = data->keys;
	mask = 1 << (keysym - XK_BackSpace + delta);
	keys->pressed |= mask;
	keys->released &= ~mask;
}

static void	store_modifier_key(t_s_data *data, int keysym)
{
	t_s_keys	*keys;
	int64_t		mask;

	keys = data->keys;
	mask = 1 << (keysym - XK_Shift_L);
	keys->modifiers |= mask;
}

void	keypress(t_s_data *data, int keysym)
{
	if (is_key_alpha(keysym))
		store_letter_key(data, keysym);
	else if (is_key_function(keysym))
		store_function_key(data, keysym);
	else if (is_key_modifier(keysym))
		store_modifier_key(data, keysym);
}
