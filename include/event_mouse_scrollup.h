/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_scrollup.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:44:52 by                   #+#    #+#             */
/*   Updated: 2023/03/10 12:44:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MOUSE_SCROLLUP_H
# define EVENT_MOUSE_SCROLLUP_H

# include <stdint.h>
# include "s_data.h"

int	event_mouse_scrollup(int32_t button, int32_t x, int32_t y, t_s_data *data);

#endif
