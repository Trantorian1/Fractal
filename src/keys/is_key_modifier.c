/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:12:13 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 09:13:58 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_key_modifier.h"

#include <X11/keysym.h>

bool	is_key_modifier(int keysym)
{
	return (keysym >= XK_Shift_L && keysym <= XK_Hyper_R);
}
