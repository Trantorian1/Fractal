/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consume_keyrelease.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:56:32 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:16:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "consume_keyrelease.h"

#include "is_key_released.h"
#include "s_data.h"
#include <stdint.h>

void	consume_keyrelease(t_s_data *data, int keysym, void *f(t_s_data *))
{
	int64_t		mask;
	t_s_keys	*keys;

	mask = is_key_released(data, keysym);
	if (mask == 0)
		return ;
	f(data);
	keys = data->keys;
	keys->released &= ~mask;
}
