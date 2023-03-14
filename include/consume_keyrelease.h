/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consume_keyrelease.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:16:21 by                   #+#    #+#             */
/*   Updated: 2023/03/14 10:16:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSUME_KEYRELEASE_H
# define CONSUME_KEYRELEASE_H

# include "s_data.h"

void	consume_keyrelease(t_s_data *data, int keysym, void *f(t_s_data *));

#endif
