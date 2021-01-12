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

	ya_h = 64;
	xa_h = 64 / tan(angle);
	if (angle > 0 && angle < M_PI || angle > M_PI * 2)
	{
		ay = (int)map->y1 / 64 * 64 - 0.0001;
		ya_h = -ya_h;
	}

	else
	{
		ay = (int)map->y1 / 64 * 64 + 64;
		xa_h = -xa_h;
	}

	ax = map->x1 + (map->y1 - ay) / tan(angle);

	if ((int)ay/64 >= 0 && (int)ay/64 < map->count && (int)ax/64 >= 0 && (int)ax/64 < 64)
	{
		while ((int)(ay/64) < map->count && ay > 0 && ax > 0 && map->map[(int) (ay / 64)][(int) (ax / 64)] != '1')
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

	xa_v = 64;
	ya_v = 64 * tan(angle);
	if (angle > M_PI_2 && angle <= M_PI * 3 / 2)
	{
		bx = (int)map->x1 / 64 * 64 - 0.0001;
		xa_v = -xa_v;
	}
	else
	{
		bx = (int)map->x1 / 64 * 64 + 64;
		ya_v = -ya_v;
	}

	by = map->y1 + (map->x1 - bx) * tan(angle);

	if ((int)(by/64) >= 0 && (int)(by/64) < map->count && (int)(bx/64) >= 0 && (int)(bx/64) < 64)
	{
		while ((int)(by/64) < map->count && by > 0 && bx > 0 && map->map[(int)by/64][(int)bx/64] != '1')
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