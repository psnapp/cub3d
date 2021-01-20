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

double		horizontal_raycasting(t_parser *map, double angle, int c)
{
	map->ya_h = CUB_SIZE;
	map->xa_h = CUB_SIZE / tan(angle);
	if (angle > 0 && angle < M_PI || angle > M_PI * 2)
	{
		map->ay = (int)map->y1 / CUB_SIZE * CUB_SIZE - 0.0001;
		map->ya_h = -map->ya_h;
	}
	else
	{
		map->ay = (int)map->y1 / CUB_SIZE * CUB_SIZE + CUB_SIZE;
		map->xa_h = -map->xa_h;
	}
	map->axx = map->x1 + (map->y1 - map->ay) / tan(angle);
	if ((int)map->ay / CUB_SIZE >= 0 && (int)map->ay / CUB_SIZE < c &&
	(int)map->axx / CUB_SIZE >= 0 && (int)map->axx / CUB_SIZE < map->max_line)
	{
		while ((int)(map->ay / CUB_SIZE) < c && map->ay > 0 && map->axx > 0 &&
		map->map[(int)(map->ay / CUB_SIZE)][(int)(map->axx / CUB_SIZE)] != '1')
		{
			map->axx += map->xa_h;
			map->ay += map->ya_h;
		}
	}
	map->ax = map->axx;
	return (sqrt((pow(map->x1 - map->ax, 2)) + pow(map->y1 - map->ay, 2)));
}

double		vertical_raycasting(t_parser *map, double angle, int c)
{
	map->xa_v = CUB_SIZE;
	map->ya_v = CUB_SIZE * tan(angle);
	if (angle > M_PI_2 && angle <= M_PI * 3 / 2)
	{
		map->bx = (int)map->x1 / CUB_SIZE * CUB_SIZE - 0.0001;
		map->xa_v = -map->xa_v;
	}
	else
	{
		map->bx = (int)map->x1 / CUB_SIZE * CUB_SIZE + CUB_SIZE;
		map->ya_v = -map->ya_v;
	}
	map->byy = map->y1 + (map->x1 - map->bx) * tan(angle);
	if ((int)(map->byy / CUB_SIZE) >= 0 && (int)(map->byy / CUB_SIZE) < c &&
	(int)(map->bx / CUB_SIZE) >= 0 && (int)(map->bx / CUB_SIZE) < map->max_line)
	{
		while ((int)(map->byy / CUB_SIZE) < c && map->byy > 0 && map->bx > 0 &&
		map->map[(int)map->byy / CUB_SIZE][(int)map->bx / CUB_SIZE] != '1')
		{
			map->bx = map->bx + map->xa_v;
			map->byy = map->byy + map->ya_v;
		}
	}
	map->by = map->byy;
	return (sqrt(pow(map->x1 - map->bx, 2) + pow(map->y1 - map->byy, 2)));
}

void		raycasting(t_parser *map)
{
	double start_angle;

	map->k = 0;
	start_angle = ft_angle(map);
	while (start_angle > (map->p_angle - M_PI_6))
	{
		map->sv = vertical_raycasting(map, start_angle, map->count);
		map->sh = horizontal_raycasting(map, start_angle, map->count);
		ft_sh_sv(map, start_angle);
		start_angle -= M_PI_3 / map->width;
		map->k++;
	}
}

double		ft_angle(t_parser *map)
{
	double start_angle;

	if (map->p_angle > 2 * M_PI)
		map->p_angle -= 2 * M_PI;
	if (map->p_angle < 0)
		map->p_angle += 2 * M_PI;
	start_angle = map->p_angle + M_PI_6;
	return (start_angle);
}

void		ft_sh_sv(t_parser *map, double start_angle)
{
	if (map->sh > map->sv)
	{
		map->dist1 = map->by;
		if (start_angle > M_PI_2 && start_angle < M_PI_2 + M_PI)
			map->flag = 'W';
		else
			map->flag = 'E';
		draw_walls(map, map->sv, start_angle);
	}
	else
	{
		map->dist1 = map->ax;
		if ((start_angle > 0 && start_angle < M_PI) || start_angle > 2 * M_PI)
			map->flag = 'N';
		else
			map->flag = 'S';
		draw_walls(map, map->sh, start_angle);
	}
}
