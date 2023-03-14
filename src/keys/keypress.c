/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:29:45 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 12:02:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keypress.h"

#include "mask_letter.h"
#include "mask_func.h"
#include "mask_motion.h"
#include "mask_modifier.h"
#include "is_key_alpha.h"
#include "is_key_function.h"
#include "is_key_motion.h"
#include "is_key_modifier.h"
#include <stdint.h>
#include <X11/keysym.h>
#include <stdio.h>

static void	store_letter_key(t_s_data *data, int keysym)
{
	int64_t		mask;

	mask = mask_letter(keysym);
	data->keys->pressed |= mask;
	data->keys->released &= ~mask;
}

static void	store_function_key(t_s_data *data, int keysym)
{
	int64_t		mask;

	mask = mask_func(keysym);
	data->keys->pressed |= mask;
	data->keys->released &= ~mask;
}

static void	store_motion_key(t_s_data *data, int keysym)
{
	int64_t		mask;

	mask = mask_motion(keysym);
	data->keys->pressed |= mask;
	data->keys->released &= ~mask;
}

static void	store_modifier_key(t_s_data *data, int keysym)
{
	int64_t		mask;

	mask = mask_modifier(keysym);
	data->keys->modifiers |= mask;
}

void	keypress(t_s_data *data, int keysym)
{
	if (is_key_alpha(keysym))
		store_letter_key(data, keysym);
	else if (is_key_function(keysym))
		store_function_key(data, keysym);
	else if (is_key_motion(keysym))
		store_motion_key(data, keysym);
	else if (is_key_modifier(keysym))
		store_modifier_key(data, keysym);
}
