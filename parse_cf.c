#include "cub3d.h"

int		parse_cf(t_parser *map, char *line, char flag)
{
	int		rgb[3];
	int		i;
	int		k;

	i = -1;
	k = 1;
	while (++i < 3)
	{
		while (line[k] == ' ')
			k++;
		rgb[i] = 0;
		while (line[k] >= '0' && line[k] <= '9')
			rgb[i] = rgb[i] * 10 + (line[k++] - '0');
		if (line[k] != ',' && i != 2)
			return (0);
		if (line[k] != '\0')
			k++;
	}
	while (line[k] == ' ')
		k++;
	if (line[k] != '\0' || !(ft_rgb(map, rgb, flag)))
		return (0);
	free(line);
	return (1);
}

int		ft_rgb(t_parser *map, int *rgb, char flag)
{
	int color;

	if (rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255)
		return (0);
	color = 0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2] << 0;
	if (flag == 'F')
	{
		if (map->f_col != -1)
			return (0);
		map->f_col = color;
	}
	else
	{
		if (map->c_col != -1)
			return (0);
		map->c_col = color;
	}
	return (1);
}
