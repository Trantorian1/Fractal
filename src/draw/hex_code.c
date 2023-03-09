/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:16:09 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 15:41:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file hex_code.c
 * @brief Color conversion functions.
 */

#include "hex_code.h"

/**
 * @brief Converts red, green and blue components to an rgx code.
 *
 * @param r (int32_t): blue channel.
 * @param g (int32_t): red channel.
 * @param b (int32_t): green channel.
 * @return (int32_t): color code.
 *
 * @warning Channels which are not in the range of [0:255] will have their value
 * set to mod 255.
 */
int32_t	hex_code(int32_t r, int32_t g, int32_t b)
{
	r %= 255;
	g %= 255;
	b %= 255;
	return (r << 16 | g << 8 | b);
}
