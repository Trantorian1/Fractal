/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:40:49 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:44:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal_loop.h"

#include "fractal_keymap.h"
#include "renderer.h"
#include <stdlib.h>

int	fractal_loop(t_s_data *data)
{
	fractal_keymap(data);
	if (data->trigger_render == true)
		renderer(data);
	return (EXIT_SUCCESS);
}
