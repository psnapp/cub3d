
#include "cub3d.h"

t_sprite	*new_sprite(t_parser *map, int i, int j)
{
	t_sprite	*tmp;
	t_sprite	*new;

	if (!(new = (t_sprite *)malloc(sizeof(t_sprite))))
		exit(0);
	if (map->sprite == NULL)
		map->sprite = new;
	else
	{
		tmp = map->sprite;
		while (tmp->next != NULL)
			tmp = map->sprite;
		tmp->next = new;
	}
	new->next = NULL;
	new->sprite_x = i * CUB_SIZE + CUB_SIZE / 2;
	new->sprite_y = j * CUB_SIZE + CUB_SIZE / 2;
	new->sprite_dist = 0;
	return (new);
}

void 	sprite(t_parser *map)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while (i < map->count)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '2')
				new_sprite(map, i, j);
			j++;
		}
		i++;
	}
}

int 	calc_sprite(t_parser *map)
{
	t_sprite	*tmp;
	int		s_h;
	double	coef;

	tmp = map->sprite;
	while (tmp != NULL)
	{
		tmp->sprite_dist = sqrt(pow(tmp->sprite_x - map->x1, 2) +
								pow(tmp->sprite_y - map->y1, 2));
		s_h = (int) ((((map->width / 2.0) / tan(M_PI_6)) / (tmp->sprite_dist * CUB_SIZE) *
					  map->height));
		map->sprite_dir = atan2((tmp->sprite_y - map->y1), (tmp->sprite_x - map->x1));
		coef = 64.0 / s_h;
		while (map->sprite_dir - map->p_angle > M_PI)
			map->sprite_dir -= 2 * M_PI;
		while (map->sprite_dir - map->p_angle < -M_PI)
			map->sprite_dir += 2 * M_PI;
		map->sprite_dir = map->sprite_dir - map->p_angle;
		map->sprite_x = map->sprite_dir * (map->width / 2) /
						(M_PI / 6) + map->width / 2 - s_h / 2;
		map->sprite_y = map->height / 2 - s_h / 2;
		draw_sprite(map, tmp, coef, s_h);
		tmp = tmp->next;
	}
}

int 	draw_sprite(t_parser *map, t_sprite *tmp, double coef, int s_h)
{
	int		i;
	int 	j;
	int		color;

	j = 0;
	while (j < s_h)
	{
		i = 0;
		while (i < s_h)
		{
			if(map->sprite_x + j < map->width && j + map->sprite_x >= 0)
			{
				color = map->tex4.t_addr[(int) (i * coef) * map->tex4.w + (int) (j * coef) % map->tex4.h];
				if (color > 0 && map->sprite_y + i > 0 && map->sprite_x + j > 0 && map->sprite_x + j < map->width && map->sprite_y + i < map->height)
					my_mlx_pixel_put(map, map->sprite_x + j, map->sprite_y + i, color);
			}
			i++;
		}
		j++;
	}
}