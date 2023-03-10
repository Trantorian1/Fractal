/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_scrolldown.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:45:12 by                   #+#    #+#             */
/*   Updated: 2023/03/10 12:45:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MOUSE_SCROLLDOWN_H
# define EVENT_MOUSE_SCROLLDOWN_H

# include <stdint.h>
# include "s_data.h"

int	event_mouse_scrolldown(int32_t button, int32_t x, int32_t y, t_s_data *data);

#endif
