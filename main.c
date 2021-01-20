/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:39:53 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/14 22:00:23 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_parser	*map;

	map = malloc(sizeof(t_parser));
	ft_init_struct(map);
	if ((map->fd = open(argv[1], O_RDONLY)) < 0)
	{
		write(1, "Error: No such file or directory\n", 33);
		exit(0);
	}
	if (!(ft_valid_args(argc, argv)) || !(parser(map, NULL)))
		exit(0);
	ft_player_2d(map);
	ft_mlx(map);
	texture_mlx(map);
	sprite(map);
	draw_all(map);
	if (argc == 3)
		screenshot(map);
	mlx_hook(map->win, 2, 1L, press_manager, map);
	mlx_hook(map->win, 3, 1L << 1, releas_manager, map);
	mlx_loop_hook(map->mlx, loop_manager, map);
	mlx_loop(map->mlx);
	return (0);
}

void	ft_mlx(t_parser *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->width, map->height, "test");
	map->img = mlx_new_image(map->mlx, map->width, map->height);
	map->addr = mlx_get_data_addr(map->img, &map->bits_per_pixel,
								&map->line_length, &map->endian);
}
