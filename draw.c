/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:05:09 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/13 16:57:59 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		tex(t_parser *map, double coef, int draw_start, int start)
{
	int color;

	if (map->flag == 'S')
		color = map->tex.t_addr[(int)((draw_start - start) * coef) * map->tex.w
		+ (map->tex1.w - 1 - ((int)(map->dist1 * 2) % map->tex1.w))];
	else if (map->flag == 'N')
		color = map->tex1.t_addr[(int)((draw_start - start) * coef) *
		map->tex1.w + ((int)(map->dist1 * 2) % map->tex1.w)];
	else if (map->flag == 'W')
		color = map->tex2.t_addr[(int)((draw_start - start) * coef) *
	map->tex2.w + ((map->tex2.w - 1) - ((int)(map->dist1 * 2) % map->tex2.w))];
	else
		color = map->tex3.t_addr[(int)((draw_start - start) * coef) *
		map->tex3.w + ((int)(map->dist1 * 2) % map->tex3.w)];
	return (color);
}

void	draw_walls(t_parser *map, double dist, double start_angle)
{
	int		draw_start;
	int		draw_end;
	int		start;

	map->begin = 0;
	map->dist_wall[map->k] = dist;
	dist = dist * cos(start_angle - map->p_angle);
	map->column_h = (int)((((map->width / 2.0) /
			tan(M_PI_6)) / (dist * CUB_SIZE)) * map->height);
	draw_start = map->height / 2 - (map->column_h / 2);
	draw_end = map->column_h / 2 + map->height / 2;
	map->coef = 64.0 / map->column_h;
	start = draw_start;
	if (draw_end > map->height)
		draw_end = map->height - 1;
	if (draw_start < 0)
		draw_start = 0;
	ft_draw_c(map, map->begin, draw_start);
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(map, map->k, draw_start,
				tex(map, map->coef, draw_start, start));
		draw_start++;
	}
	ft_draw_f(map, draw_start, draw_end);
}

void	ft_draw_c(t_parser *map, double begin, int draw_start)
{
	while (begin < draw_start)
	{
		my_mlx_pixel_put(map, map->k, begin, map->c_col);
		begin++;
	}
}

void	ft_draw_f(t_parser *map, int draw_start, int draw_end)
{
	while (draw_start < map->height)
	{
		my_mlx_pixel_put(map, map->k, draw_start, map->f_col);
		draw_start++;
	}
}
