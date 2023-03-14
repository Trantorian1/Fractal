/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:19:46 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 12:04:23 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyrelease.h"

#include "mask_letter.h"
#include "mask_func.h"
#include "mask_motion.h"
#include "mask_modifier.h"
#include "is_key_alpha.h"
#include "is_key_function.h"
#include "is_key_modifier.h"
#include "is_key_motion.h"
#include <stdint.h>
#include <X11/keysym.h>
#include <stdio.h>

static void	release_letter_key(t_s_data *data, int keysym)
{
	int64_t		mask;

	mask = mask_letter(keysym);
	data->keys->pressed &= ~mask;
	data->keys->released |= mask;
}

static void	release_function_key(t_s_data *data, int keysym)
{
	int64_t					mask;

	mask = mask_func(keysym);
	data->keys->pressed &= ~mask;
	data->keys->released |= mask;
}

static void	release_motion_key(t_s_data *data, int keysym)
{
	int64_t		mask;

	mask = mask_motion(keysym);
	data->keys->pressed &= ~mask;
	data->keys->released |= mask;
}

static void	release_modifier_key(t_s_data *data, int keysym)
{
	int64_t		mask;

	mask = mask_modifier(keysym);
	data->keys->modifiers &= ~mask;
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
