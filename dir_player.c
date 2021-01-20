/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:55:12 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/10 11:49:34 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dir_player(t_parser *map)
{
	if (map->flag == 'E')
		map->p_angle = 0;
	else if (map->flag == 'N')
		map->p_angle = M_PI_2;
	else if (map->flag == 'W')
		map->p_angle = M_PI;
	else if (map->flag == 'S')
		map->p_angle = M_PI_2 * 3;
}
