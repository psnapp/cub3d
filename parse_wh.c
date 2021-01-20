/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:28:44 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/08 15:29:12 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_wh(t_parser *map, char *line)
{
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		if ((map->width * 10 + (line[i] - '0')) > 21474836)
			return (0);
		map->width = map->width * 10 + (line[i++] - '0');
	}
	while (line[i] == ' ')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
	{
		if ((map->height * 10 + (line[i] - '0')) > 21474836)
			return (0);
		map->height = map->height * 10 + (line[i++] - '0');
	}
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0' || map->width < 0 || map->height < 0)
		return (0);
	free(line);
	return (1);
}
