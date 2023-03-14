/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:55:35 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 11:57:09 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mask_func.h"

#include "normalise_key_function.h"
#include <X11/keysym.h>

static const int64_t	g_delta_func = XK_Z - XK_A;

int64_t	mask_func(int keysym)
{
	return (1 << (normalise_key_func(keysym) + g_delta_func));
}
