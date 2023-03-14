/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:35:26 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 12:55:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_key_pressed.h"

#include "mask_letter.h"
#include "mask_func.h"
#include "mask_motion.h"
#include "mask_modifier.h"
#include "is_key_alpha.h"
#include "is_key_function.h"
#include "is_key_motion.h"
#include "is_key_modifier.h"
#include <X11/keysym.h>
#include <stdint.h>
#include <stdio.h>

static int64_t	is_key_letter_pressed(t_s_data *data, int keysym)
{
	int64_t	mask;

	mask = mask_letter(keysym);
	return ((data->keys->pressed & mask) > 0 * mask);
}

static int64_t	is_key_function_pressed(t_s_data *data, int keysym)
{
	int64_t	mask;

	mask = mask_func(keysym);
	return ((data->keys->pressed & mask) > 0 * mask);
}

static int64_t	is_key_motion_pressed(t_s_data *data, int keysym)
{
	int64_t	mask;

	mask = mask_motion(keysym);
	return ((data->keys->pressed & mask) > 0 * mask);
}

static int64_t	is_key_modifier_pressed(t_s_data *data, int keysym)
{
	int64_t	mask;

	mask = mask_modifier(keysym);
	return ((data->keys->modifiers & mask) > 0 * mask);
}

int64_t	is_key_pressed(t_s_data *data, int keysym)
{
	if (is_key_alpha(keysym))
		return (is_key_letter_pressed(data, keysym));
	else if (is_key_function(keysym))
		return (is_key_function_pressed(data, keysym));
	else if (is_key_motion(keysym))
		return (is_key_motion_pressed(data, keysym));
	else if (is_key_modifier(keysym))
		return (is_key_modifier_pressed(data, keysym));
	return (0x0);
}
