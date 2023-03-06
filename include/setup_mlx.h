/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:46:10 by                   #+#    #+#             */
/*   Updated: 2023/03/06 16:46:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_MLX_H
# define SETUP_MLX_H

# include <stdint.h>
# include "s_data.h"

t_s_data	*setup_mlx(int16_t width, int16_t height, char *title);

#endif