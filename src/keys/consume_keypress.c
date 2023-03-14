/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consume_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:31:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:52:24 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "consume_keypress.h"

#include "is_key_pressed.h"
#include "s_data.h"
#include <X11/keysym.h>
#include <stdint.h>

static bool	validate_keycomb(t_s_data *data, t_s_keycomb *keycomb)
{
	t_s_keys	*keys;
	int32_t		i;
	int64_t		masks[KEYCOMB_MAX];

	keys = data->keys;
	i = 0;
	while (i < keycomb->size)
	{
		masks[i] = is_key_pressed(data, keycomb->keys[i]);
		if (masks[i] == 0)
			return (false);
		i++;
	}
	i = 0;
	while (i < keycomb->size)
	{
		keys->pressed &= ~masks[i];
		i++;
	}
	return (true);
}

void	consume_keypress(t_s_data *data, t_s_keycomb *keycomb)
{
	if (validate_keycomb(data, keycomb) == false)
		return ;
	keycomb->handler(data);
}
