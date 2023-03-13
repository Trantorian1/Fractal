/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_up.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:33:33 by                   #+#    #+#             */
/*   Updated: 2023/03/13 17:33:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MOUSE_UP_H
# define EVENT_MOUSE_UP_H

# include <stdint.h>
# include "s_data.h"

int	event_mouse_up(int32_t button, int32_t x, int32_t y, t_s_data *data);

#endif
