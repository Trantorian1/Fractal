/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consume_keypress.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:29:56 by                   #+#    #+#             */
/*   Updated: 2023/03/14 10:29:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSUME_KEYPRESS_H
# define CONSUME_KEYPRESS_H

# include "s_data.h"

void	consume_keypress(t_s_data *data, int keysym, void f(t_s_data *));

#endif
