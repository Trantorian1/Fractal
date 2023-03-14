/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key_released.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:07:03 by                   #+#    #+#             */
/*   Updated: 2023/03/14 10:07:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_KEY_RELEASED_H
# define IS_KEY_RELEASED_H

# include <stdint.h>
# include "s_data.h"

int64_t	is_key_released(t_s_data *data, int keysym);

#endif