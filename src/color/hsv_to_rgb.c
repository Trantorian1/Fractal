/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:35:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 21:15:18 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsv_to_rgb.h"

#include <math.h>

int32_t	hsv_to_rgb(double h, double s, double v)
{
	int32_t r, g, b;
  int32_t i;
  double f, p, q, t;

  if (s == 0) {
    // Achromatic (gray)
    r = g = b = (int32_t) round(v * 255);
  } else {
	h /= 60; // sector 0 to 5
    i = (int) floor(h);
    f = h - i; // factorial part of h
    p = v * (1 - s);
    q = v * (1 - s * f);
    t = v * (1 - s * (1 - f));

    switch (i) {
      case 0:
        r = (int32_t) round(v * 255);
        g = (int32_t) round(t * 255);
        b = (int32_t) round(p * 255);
        break;
      case 1:
        r = (int32_t) round(q * 255);
        g = (int32_t) round(v * 255);
        b = (int32_t) round(p * 255);
        break;
      case 2:
        r = (int32_t) round(p * 255);
        g = (int32_t) round(v * 255);
        b = (int32_t) round(t * 255);
        break;
      case 3:
        r = (int32_t) round(p * 255);
        g = (int32_t) round(q * 255);
        b = (int32_t) round(v * 255);
        break;
      case 4:
        r = (int32_t) round(t * 255);
        g = (int32_t) round(p * 255);
        b = (int32_t) round(v * 255);
        break;
      default: // case 5:
        r = (int32_t) round(v * 255);
        g = (int32_t) round(p * 255);
        b = (int32_t) round(q * 255);
        break;
    }
  }

  return (r << 16) | (g << 8) | b;
}
