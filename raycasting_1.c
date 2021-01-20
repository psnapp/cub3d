/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:31:07 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/17 18:02:22 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	horizontal_raycasting(t_parser *map, double angle)
{
	double ay;
	double ax;
	double xa_h;
	double ya_h;

	ya_h = CUB_SIZE;
	xa_h = CUB_SIZE / tan(angle);
	if (angle > 0 && angle < M_PI || angle > M_PI * 2)
	{
		ay = (int)map->y1 / CUB_SIZE * CUB_SIZE - 0.0001;
		ya_h = -ya_h;
	}

	else
	{
		ay = (int)map->y1 / CUB_SIZE * CUB_SIZE + CUB_SIZE;
		xa_h = -xa_h;
	}

	ax = map->x1 + (map->y1 - ay) / tan(angle);

	if ((int)ay/CUB_SIZE >= 0 && (int)ay/CUB_SIZE < map->count && (int)ax/CUB_SIZE >= 0 && (int)ax/CUB_SIZE < map->max_line)
	{
		while ((int)(ay/CUB_SIZE) < map->count && ay > 0 && ax > 0 && map->map[(int) (ay / CUB_SIZE)][(int) (ax / CUB_SIZE)] != '1')
		{
			ax += xa_h;
			ay += ya_h;
		}
	}
	map->ax = ax;
	return (sqrt((pow(map->x1 - ax, 2)) + pow(map->y1 - ay, 2)));
}

double	vertical_raycasting(t_parser *map, double angle)
{
	double by;
	double bx;
	double xa_v;
	double ya_v;

	xa_v = CUB_SIZE;
	ya_v = CUB_SIZE * tan(angle);
	if (angle > M_PI_2 && angle <= M_PI * 3 / 2)
	{
		bx = (int)map->x1 / CUB_SIZE * CUB_SIZE - 0.0001;
		xa_v = -xa_v;
	}
	else
	{
		bx = (int)map->x1 / CUB_SIZE * CUB_SIZE + CUB_SIZE;
		ya_v = -ya_v;
	}

	by = map->y1 + (map->x1 - bx) * tan(angle);

	if ((int)(by/CUB_SIZE) >= 0 && (int)(by/CUB_SIZE) < map->count && (int)(bx/CUB_SIZE) >= 0 && (int)(bx/CUB_SIZE) < map->max_line)
	{
		while ((int)(by/CUB_SIZE) < map->count && by > 0 && bx > 0 && map->map[(int)by/CUB_SIZE][(int)bx/CUB_SIZE] != '1')
		{
			bx = bx + xa_v;
			by = by + ya_v;
		}
	}
	map->by = by;
	return (sqrt(pow(map->x1 - bx, 2) + pow(map->y1 - by, 2)));
}

void	raycasting(t_parser *map)
{
	double start_angle;
	int k;
	k = 0;

	if (map->p_angle > 2 * M_PI)
		map->p_angle -= 2 * M_PI;
	if (map->p_angle < 0)
		map->p_angle += 2 * M_PI;
	start_angle = map->p_angle + M_PI_6;
	while (start_angle > (map->p_angle - M_PI_6))
	{
		double sv = vertical_raycasting(map, start_angle);
		double sh = horizontal_raycasting(map, start_angle);
		if (sh > sv)
		{
			map->dist1 = map->by;
			if (start_angle > M_PI_2 && start_angle < M_PI_2 + M_PI)
				map->flag = 'W';
			else
				map->flag = 'E';
			draw_walls(map, k, sv, start_angle);
		}
		else
		{
			map->dist1 = map->ax;
			if ((start_angle > 0 && start_angle < M_PI) || start_angle > 2 * M_PI)
				map->flag = 'N';
			else
				map->flag = 'S';
			draw_walls(map, k, sh, start_angle);
		}
		start_angle -= M_PI_3 / map->width;
		k++;
	}
}