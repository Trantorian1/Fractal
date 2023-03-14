/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_keymap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:18:35 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:32:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_keymap.h"

#include "handle_esc.h"
#include "consume_keypress.h"
#include <X11/keysym.h>
#include <stdio.h>

#define MAP_SIZE 2

typedef void	(t_key_handlers)(t_s_data *);

static const int		g_keysym_map[MAP_SIZE] = {
	XK_A,
	XK_Escape
};

static void	test(t_s_data *data);
static t_key_handlers	*g_map_handler[MAP_SIZE] = {
	*test,
	*handle_esc
};

static void	test(t_s_data *data)
{
	(void)data;
	printf("A key pressed !\n");
}

void	fractal_keymap(t_s_data *data)
{
	int32_t	i;

	i = 0;
	while (i < MAP_SIZE)
	{
		consume_keypress(data, g_keysym_map[i], g_map_handler[i]);
		i++;
	}
}
