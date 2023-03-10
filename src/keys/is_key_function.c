/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:47:31 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 11:39:35 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_key_function.h"

#include "normalise_key_function.h"
#include <X11/keysym.h>

bool	is_key_function(int keysym)
{
	return (normalise_key_func(keysym) != -1);
}
