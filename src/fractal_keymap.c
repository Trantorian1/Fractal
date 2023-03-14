/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_keymap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:18:35 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 13:23:32 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_keymap.h"

#include "handle_left_arrow.h"
#include "handle_right_arrow.h"
#include "handle_up_arrow.h"
#include "handle_down_arrow.h"
#include "handle_r.h"
#include "handle_esc.h"
#include "consume_keypress.h"
#include "s_keycomb.h"
#include <X11/keysym.h>
#include <stdio.h>

static t_s_keycomb	g_keymap[] = {
{.size = 1, .keys = {XK_Left}, .handler = &handle_left_arrow},
{.size = 1, .keys = {XK_Right}, .handler = &handle_right_arrow},
{.size = 1, .keys = {XK_Up}, .handler = &handle_up_arrow},
{.size = 1, .keys = {XK_Down}, .handler = &handle_down_arrow},
{.size = 1, .keys = {XK_Escape}, .handler = &handle_esc},
{.size = 1, .keys = {XK_R}, .handler = &handle_r},
};

void	fractal_keymap(t_s_data *data)
{
	int32_t	i;
	int32_t	target;

	i = 0;
	target = sizeof(g_keymap) / sizeof(*g_keymap);
	while (i < target)
	{
		consume_keypress(data, &g_keymap[i]);
		i++;
	}
}
