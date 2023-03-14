/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consume_keypress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:31:52 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:29:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "consume_keypress.h"

#include "is_key_pressed.h"
#include "s_data.h"
#include <X11/keysym.h>
#include <stdint.h>

void	consume_keypress(t_s_data *data, int keysym, void f(t_s_data *))
{
	int64_t		mask;
	t_s_keys	*keys;

	mask = is_key_pressed(data, keysym);
	if (mask == 0)
		return ;
	f(data);
	keys = data->keys;
	keys->pressed &= ~mask;
}
