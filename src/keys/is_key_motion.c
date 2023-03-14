/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:59:43 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 11:29:34 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_key_motion.h"

#include <X11/keysym.h>
#include <stdio.h>

bool	is_key_motion(int keysym)
{
	return (keysym >= XK_Home && keysym <= XK_Begin);
}
