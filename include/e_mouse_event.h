/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_mouse_event.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:39:41 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/10 12:47:37 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_MOUSE_EVENT_H
# define E_MOUSE_EVENT_H

typedef enum e_mouse_event
{
	NONE,
	LEFT_CLICK,
	RIGHT_CLICK,
	MIDDLE_CLICK,
	SCROLL_UP,
	SCROLL_DOWN,
	E_MOUSE_EVENT_SIZE
}	t_e_mouse_event;

#endif
