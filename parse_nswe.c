#include "cub3d.h"

int		parse_so(t_parser *map, char *line)
{
	int		i;
	int		k;

	i = 2;
	k = 0;
	if (!(map->str_so = (char *)malloc(sizeof(*map->str_so) * ft_strlen(line))))
		return (0);
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		map->str_so[k] = line[i];
		i++;
		k++;
	}
	map->str_so[k] = '\0';
	free(line);
}

int		parse_n(t_parser *map, char *line)
{
	int		i;
	int		k;

	i = 2;
	k = 0;
	if (!(map->str_no = (char *)malloc(sizeof(*map->str_no) * ft_strlen(line))))
		return (0);
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		map->str_no[k] = line[i];
		i++;
		k++;
	}
	map->str_no[k] = '\0';
	free(line);
}

int		parse_w(t_parser *map, char *line)
{
	int		i;
	int		k;

	i = 2;
	k = 0;
	if (!(map->str_we = (char *)malloc(sizeof(*map->str_we) * ft_strlen(line))))
		return (0);
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		map->str_we[k] = line[i];
		i++;
		k++;
	}
	map->str_we[k] = '\0';
	free(line);
}

int		parse_e(t_parser *map, char *line)
{
	int		i;
	int		k;

	i = 2;
	k = 0;
	if (!(map->str_ea = (char *)malloc(sizeof(*map->str_ea) * ft_strlen(line))))
		return (0);
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		map->str_ea[k] = line[i];
		i++;
		k++;
	}
	map->str_ea[k] = '\0';
	free(line);
}

int		parse_s(t_parser *map, char *line)
{
	int		i;
	int		k;

	i = 1;
	k = 0;
	if (!(map->str_s = (char *)malloc(sizeof(*map->str_s) * ft_strlen(line))))
		return (0);
	while (line[i] == ' ')
		i++;
	while (line[i])
	{
		map->str_s[k] = line[i];
		i++;
		k++;
	}
	map->str_s[k] = '\0';
	free(line);
}
