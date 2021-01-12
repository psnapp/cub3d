
#include "cub3d.h"

int 	sprite(t_parser *map)
{
	int		i;
	int 	j;

	i = 0;
	while (map->map[i]][j])
	{
		j = 0;
		while (map->map[i]][j])
		{
			if (map->map[i][j] == '2')
			{
				new_sprite(map, i, j);
			}
			j++;
		}
		i++;
	}
}

int 	new_sprite(t_parser *map, int i, int j)
{
	t_list	*tmp;
	if ()
	tmp = (t_list *)malloc(sizeof(t_list));

}