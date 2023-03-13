/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_do_nothing.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:11:47 by                   #+#    #+#             */
/*   Updated: 2023/03/13 17:11:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_MOUSE_DO_NOTHING_H
# define EVENT_MOUSE_DO_NOTHING_H

# include <stdint.h>
# include "s_data.h"

int	event_mouse_do_nothing(int32_t button, int32_t x, int32_t y, t_s_data *data);

#endif
