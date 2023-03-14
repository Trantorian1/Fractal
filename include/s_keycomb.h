/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_keycomb.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:36:51 by emcnab            #+#    #+#             */
/*   Updated: 2023/03/14 10:42:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_KEYCOMB_H
# define S_KEYCOMB_H

# include "s_data.h"
# include <stdint.h>

# define KEYCOMB_MAX 4

typedef void	(t_handler)(t_s_data *);

typedef struct s_keycomb
{
	int32_t		size;
	int32_t		keys[4];
	t_handler	*handler;
}	t_s_keycomb;

#endif
