/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:57:24 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 11:58:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mask_motion.h"

#include <X11/keysym.h>

static const int64_t	g_delta_motion = XK_Z - XK_A + 10;

int64_t	mask_motion(int keysym)
{
	return (1 << (keysym - XK_Home + g_delta_motion));
}
