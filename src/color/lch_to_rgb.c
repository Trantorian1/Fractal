/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lch_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:59:07 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/09 19:08:25 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lchToRgb.h"

#include <math.h>

// helper function to convert degrees to radians
double degToRad(double deg) {
  return deg * M_PI / 180.0;
}

// helper function to convert XYZ to RGB
int xyzToRgb(double val) {
  if (val > 0.0031308) {
    return round(255.0 * (1.055 * pow(val, 1.0/2.4) - 0.055));
  } else {
    return round(255.0 * (12.92 * val));
  }
}

// main function to convert LCH to RGB
int lchToRgb(LCHColor lch) {
	double L = lch.L;
	double C = lch.C;
	double H = degToRad(lch.H);

	double u = C * cos(H);
	double v = C * sin(H);

	double x = L + 0.396337 * u + 0.215803 * v;
	double y = L - 0.105561 * u - 0.063854 * v;
	double z = L - 0.089484 * u - 1.291485 * v;

	int r = xyzToRgb(3.2406 * x - 1.5372 * y - 0.4986 * z);
	int g = xyzToRgb(-0.9689 * x + 1.8758 * y + 0.0415 * z);
	int b = xyzToRgb(0.0557 * x - 0.2040 * y + 1.0570 * z);

	return ((r << 16) | (g << 8) | b);
}
