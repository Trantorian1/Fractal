/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_keymap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:18:35 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:56:47 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_keymap.h"

#include "handle_esc.h"
#include "consume_keypress.h"
#include "s_keycomb.h"
#include <X11/keysym.h>
#include <stdio.h>

#define MAP_SIZE 2

static void	test(t_s_data *data);
static t_s_keycomb	g_keymap[] = {
{.size = 2, .keys = {XK_Shift_L, XK_A}, .handler = &test},
{.size = 1, .keys = {XK_Escape}, .handler = &handle_esc}
};

static void	test(t_s_data *data)
{
	(void)data;
	printf("S-A key pressed !\n");
}

void	fractal_keymap(t_s_data *data)
{
	int32_t	i;

	i = 0;
	while (i < MAP_SIZE)
	{
		consume_keypress(data, &g_keymap[i]);
		i++;
	}
}
