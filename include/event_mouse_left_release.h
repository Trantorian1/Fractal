/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_left_release.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:37:26 by                   #+#    #+#             */
/*   Updated: 2023/03/13 17:38:13 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MOUSE_LEFT_RELEASE_H
# define EVENT_MOUSE_LEFT_RELEASE_H

# include <stdint.h>
# include "s_data.h"

int	event_mouse_left_release(
	int32_t button,
	int32_t x,
	int32_t y,
	t_s_data *data);

#endif
