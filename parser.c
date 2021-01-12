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

int		parser(t_parser *map)
{
	char	*line;
	char	flag;

	while (get_next_line(map->fd, &line) > 0)
	{
		if (line[0] == 'R' && line[1] == ' ')
		{
			parse_wh(map, line);
		}
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
		{
			flag = 'C';
			parse_cf(map, line, flag);
		}
		else if (line[0] == 'F' && line[1] == ' ')
		{
			flag = 'F';
			parse_cf(map, line, flag);
		}
		else if (line[0] == '1' || line[0] == ' ')
		{
			parse_map(map, line);
		}
		else
		{
			write(1, "invalid map\n", 12);
			return (0);
		}
	}
	return (1);
}