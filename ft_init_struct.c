/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 15:27:37 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/13 16:50:55 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct(t_parser *map)
{
	map->count = 0;
	map->width = 0;
	map->height = 0;
	map->f_col = -1;
	map->c_col = -1;
	map->str_s = NULL;
	map->str_ea = NULL;
	map->str_we = NULL;
	map->str_so = NULL;
	map->str_no = NULL;
	map->tex.w = 0;
	map->tex.h = 0;
}