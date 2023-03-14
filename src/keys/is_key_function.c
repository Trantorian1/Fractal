/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:47:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 09:49:01 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_key_function.h"

#include <X11/keysym.h>

bool	is_key_function(int keysym)
{
	return (keysym >= XK_BackSpace && keysym <= XK_Delete);
}
