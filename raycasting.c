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

int	loop_manager(t_parser *map)
{
	key_press(map);
	draw_all(map);
	return(1);
}

int  press_manager(int key, t_parser *map)
{
	if (key == 123 )
		map->key_123 = 1;
	if (key == 124 )
		map->key_124 = 1;
	if (key == 53)
		map->key_ex = 1;
	if (key == 1 )
		map->key_s = 1;
	if (key == 13)
		map->key_w = 1;
	if (key == 2)
		map->key_right = 1;
	if (key == 0)
		map->key_left = 1;
	return(1);
}

int releas_manager(int key, t_parser *map)
{
	if (key == 123 && map->key_123== 1)
		map->key_123 = 0;
	if (key == 124 && map->key_124== 1)
		map->key_124 = 0;
	if (key == 1 && map->key_s == 1)
		map->key_s = 0;
	if (key == 13 && map->key_w == 1)
		map->key_w = 0;
	if (key == 2 && map->key_right == 1)
		map->key_right = 0;
	if (key == 0 && map->key_left == 1)
		map->key_left = 0;
	return(1);
}

void	ft_map_2d(t_parser *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->count)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				draw(map, j*PIX, i*PIX, PIX);
			j++;
		}
		i++;
	}
}

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
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || map->map[i][j] == 'E'
			|| map->map[i][j] == 'W')
			{
				map->flag = map->map[i][j];
				dir_player(map);
				map->y1 = (i * CUB_SIZE) + (CUB_SIZE / 2);
				map->x1 = (j * CUB_SIZE) + (CUB_SIZE / 2);
			}
			j++;
		}
		i++;
	}
}

int		key_press(t_parser *map)
{
//	mlx_destroy_image(map->mlx, map->img);	 // уничтожение картинки
	if (map->key_s == 1)
	{
		map->x1 -= cos(map->p_angle) * 3;
		map->y1 += sin(map->p_angle) * 3;
	}
	if (map->key_w == 1)
	{
		map->x1 += cos(map->p_angle) * 3;
		map->y1 -= sin(map->p_angle) * 3;
	}
	if (map->key_right == 1)
	{
		map->x1 += sin(map->p_angle) * 3;
		map->y1 += cos(map->p_angle) * 3;
	}
	if (map->key_left == 1)
	{
		map->x1 -= sin(map->p_angle) * 3;
		map->y1 -= cos(map->p_angle) * 3;
	}
	if (map->key_ex == 1)
		exit(0);
	if (map->key_123 == 1)
	{
		map->p_angle += M_PI / 90;
	}
	if (map->key_124 == 1)
	{
		map->p_angle -= M_PI / 90;
	}
	draw_all(map);
	return (0);
}

void            my_mlx_pixel_put(t_parser *map, int x, int y, int color)
{
    char    *dst;

	if (y < map->height && x < map->width && y >= 0 && x >= 0)
	{
		dst = map->addr + (y * map->line_length + x * (map->bits_per_pixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	draw_all(t_parser *map)
{
	//ft_map_2d(map);
	 if (map->map[(int)map->y1/64][(int)map->x1/64] == '1')
	 {
	  	map->x1 = map->x;
	  	map->y1 = map->y;
	 }
	 map->x = map->x1;
	 map->y = map->y1;

	//draw1(map, map->y1*PIX, map->x1*PIX, PIX);

	raycasting(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}