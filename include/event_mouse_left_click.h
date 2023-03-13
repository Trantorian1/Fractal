/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_left_click.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:35:43 by                   #+#    #+#             */
/*   Updated: 2023/03/13 17:35:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MOUSE_LEFT_CLICK_H
# define EVENT_MOUSE_LEFT_CLICK_H

# include <stdint.h>
# include "s_data.h"

int	event_mouse_left_click(int32_t button, int32_t x, int32_t y, t_s_data *data);

#endif
