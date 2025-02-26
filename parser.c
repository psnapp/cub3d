/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:34:51 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/08 16:18:15 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parser(t_parser *map, char *line)
{
	while (get_next_line(map->fd, &line) > 0)
		if (line[0] == 'R' && line[1] == ' ')
			parse_wh(map, line);
		else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
			parse_so(map, line);
		else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
			parse_n(map, line);
		else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
			parse_w(map, line);
		else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
			parse_e(map, line);
		else if (line[0] == 'S' && line[1] == ' ')
			parse_s(map, line);
		else if (line[0] == 'C' && line[1] == ' ')
			parse_cf(map, line, 'C');
		else if (line[0] == 'F' && line[1] == ' ')
			parse_cf(map, line, 'F');
		else if (line[0] == '1' || line[0] == ' ')
			parse_map(map, line);
		else
			free(line);
	check(map);
	free(line);
	return (1);
}

int		check(t_parser *map)
{
	if (!map->str_s || !map->str_so || !map->str_ea ||
	!map->str_no || !map->str_we || !map->map)
	{
		write(1, "invalid map\n", 12);
		free(map->map);
		exit(0);
	}
	map->dist_wall = (int *)malloc(map->width * sizeof(int));
}

int		check_map(int h, int x, int y, char **map_check)
{
	if ((x > ft_strlen(map_check[y]) - 1) || map_check[y][x] == ' ')
		return (0);
	if (map_check[y][x] == '1')
		return (1);
	else if (y == 0 || y == h || x == 0 ||
	(size_t)x == ft_strlen(map_check[y]) - 1)
		return (0);
	if (map_check[y][x] == '*')
		return (1);
	map_check[y][x] = '*';
	if (!(check_map(h, x + 1, y, map_check)))
		return (0);
	if (!(check_map(h, x - 1, y, map_check)))
		return (0);
	if (!(check_map(h, x, y - 1, map_check)))
		return (0);
	if (!(check_map(h, x, y - 1, map_check)))
		return (0);
	return (1);
}
