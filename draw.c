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

void	draw(t_parser *map, int x0, int y0, int s)
{
	int x;
	int y;

	x = x0;
	while (x < x0 + s)
	{
		y = y0;
		while (y < y0 + s)
		{
			my_mlx_pixel_put(map, x, y, 0x00BFFF);
			y++;
		}
		x++;
	}
}

void	draw1(t_parser *map, int x0, int y0, int s)
{
	int x;
	int y;

	x = x0;
	while (x < x0 + s)
	{
		y = y0;
		while (y < y0 +s)
		{
			my_mlx_pixel_put(map, x, y, 0xFFC0CB);
			y++;
		}
		x++;
	}
}

int 	tex(t_parser *map, double coef, int draw_start, int start)
{
	int color;
	if (map->flag == 'S')
		color = map->tex.t_addr[(int)((draw_start - start) * coef) * map->tex.w  + (map->tex1.w - 1 - ((int)(map->dist1 * 2) % map->tex1.w))];

	else if (map->flag == 'N')
		color = map->tex1.t_addr[(int)((draw_start - start) * coef) * map->tex1.w + ((int)(map->dist1 * 2) % map->tex1.w)];

	else if (map->flag == 'W')
		color = map->tex2.t_addr[(int)((draw_start - start) * coef) * map->tex2.w + ((map->tex2.w - 1) - ((int)(map->dist1 * 2) % map->tex2.w))];

	else
		color = map->tex3.t_addr[(int)((draw_start - start) * coef) * map->tex3.w + ((int)(map->dist1 * 2) % map->tex3.w)];
	return (color);
}

void	draw_walls(t_parser *map, int i, double dist, double start_angle)
{
	double begin;
	int column_h;
	int draw_start;
	int draw_end;
	double coef;
	int start;

	begin = 0;


	dist = dist * cos(start_angle - map->p_angle);
	column_h = (int)((((map->width / 2.0) / tan(M_PI_6)) / (dist * 64)) * map->height);
	draw_start = map->height / 2 - (column_h / 2) ;
	draw_end = column_h / 2 + map->height / 2;
	coef = 64.0 / column_h;
	start = draw_start;
	if (draw_end > map->height)
		draw_end = map->height - 1;
	if (draw_start < 0)
		draw_start = 0;
	while (begin < draw_start)
	{
		my_mlx_pixel_put(map, i, begin, map->c_col);
		begin++;
	}
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(map, i, draw_start, tex(map, coef, draw_start, start));
		draw_start++;
	}
	while (draw_start < map->height)
	{
		my_mlx_pixel_put(map, i, draw_start, map->f_col);
		draw_start++;
	}
}
