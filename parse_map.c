/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:53:56 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/13 17:25:53 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_map(t_parser *map, char *line)
{
	map->map = ft_add_line_to_array(map, line);
	map->count++;
	return (1);
}

char		**ft_add_line_to_array(t_parser *map, char *line)
{
	char	**arr;
	int		j;
	int		i;

	i = 0;
	if(!(arr = (char **)malloc(sizeof(char *) * (map->count + 2))))
		return (NULL);
	ft_bzero(arr, sizeof(char *) * (map->count + 2));
	while (i < map->count)
	{
		arr[i] = map->map[i];
		i++;
	}
	arr[i] = line;
	return(arr);
}