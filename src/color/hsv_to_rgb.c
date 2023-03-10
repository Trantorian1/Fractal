/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:35:19 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 14:54:22 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsv_to_rgb.h"

#include "to_rgb.h"
#include <float.h>
#include <math.h>

typedef struct s_rgb
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
}	t_s_rgb;

typedef struct s_hsv
{
	double	h;
	double	s;
	double	v;
}	t_s_hsv;

typedef struct s_pqt
{
	double	p;
	double	q;
	double	t;
}	t_s_pqt;

static void	pqt_switch(
	t_s_rgb *rgb,
	t_s_hsv *hsv,
	t_s_pqt *pqt,
	int32_t sextant)
{
	if (sextant == 0)
		return ((void)(rgb->r = (int32_t)(hsv->v * 255)),
				(void)(rgb->g = (int32_t)(pqt->t * 255)),
				(void)(rgb->b = (int32_t)(pqt->p * 255)));
	if (sextant == 1)
		return ((void)(rgb->r = (int32_t)(pqt->q * 255)),
				(void)(rgb->g = (int32_t)(hsv->v * 255)),
				(void)(rgb->b = (int32_t)(pqt->p * 255)));
	if (sextant == 2)
		return ((void)(rgb->r = (int32_t)(pqt->p * 255)),
				(void)(rgb->g = (int32_t)(hsv->v * 255)),
				(void)(rgb->b = (int32_t)(pqt->t * 255)));
	if (sextant == 3)
		return ((void)(rgb->r = (int32_t)(pqt->p * 255)),
				(void)(rgb->g = (int32_t)(pqt->q * 255)),
				(void)(rgb->b = (int32_t)(hsv->v * 255)));
	if (sextant == 4)
		return ((void)(rgb->r = (int32_t)(pqt->t * 255)),
				(void)(rgb->g = (int32_t)(pqt->p * 255)),
				(void)(rgb->b = (int32_t)(hsv->v * 255)));
	if (sextant == 5)
		return ((void)(rgb->r = (int32_t)(hsv->v * 255)),
				(void)(rgb->g = (int32_t)(pqt->p * 255)),
				(void)(rgb->b = (int32_t)(pqt->q * 255)));
}

static void	get_rgb(t_s_rgb *rgb, t_s_hsv *hsv)
{
	int32_t	sextant;
	double	factorial;
	t_s_pqt	pqt;

	hsv->h /= 60;
	sextant = (int32_t)hsv->h;
	factorial = hsv->h - sextant;
	pqt.p = hsv->v * (1 - hsv->s);
	pqt.q = hsv->v * (1 - hsv->s * factorial);
	pqt.t = hsv->v * (1 - hsv->s * (1 - factorial));
	pqt_switch(rgb, hsv, &pqt, sextant);
}

int32_t	hsv_to_rgb(double h, double s, double v)
{
	t_s_hsv	hsv;
	t_s_rgb	rgb;
	int32_t	vi;

	if (h >= 360)
		h = fmod(h, 360);
	if (s <= DBL_EPSILON)
	{
		vi = (int32_t)(v * 255);
		return (to_rgb(vi, vi, vi));
	}
	hsv.h = h;
	hsv.s = s;
	hsv.v = v;
	get_rgb(&rgb, &hsv);
	return (to_rgb(rgb.r, rgb.g, rgb.b));
}
