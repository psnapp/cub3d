/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:04:56 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/17 18:00:19 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_2d(t_parser *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->count)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
			|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->flag = map->map[i][j];
				dir_player(map);
				map->i = i;
				map->j = j;
				map->y1 = (i * CUB_SIZE) + (CUB_SIZE / 2);
				map->x1 = (j * CUB_SIZE) + (CUB_SIZE / 2);
			}
			j++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_parser *map, int x, int y, int color)
{
	char	*dst;

	if (y < map->height && x < map->width && y >= 0 && x >= 0)
	{
		dst = map->addr + (y * map->line_length + x
				* (map->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_all(t_parser *map)
{
	if (!check_map(map->height, map->j, map->i, map->map))
	{
		write(1, "invalid map\n", 12);
		exit(0);
	}
	if (map->map[(int)map->y1 / CUB_SIZE][(int)map->x1 / CUB_SIZE] == '1')
	{
		map->x1 = map->x;
		map->y1 = map->y;
	}
	map->x = map->x1;
	map->y = map->y1;
	raycasting(map);
	if (map->sprite != NULL)
		calc_sprite(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}
