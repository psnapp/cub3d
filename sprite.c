
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
			tmp = tmp->next;
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

void 	calc_sprite(t_parser *map)
{
	t_sprite	*tmp;

	tmp = map->sprite;
	while (tmp != NULL)
	{
		tmp->sprite_dir = atan2(map->y1 - tmp->sprite_y, tmp->sprite_x - map->x1);
		if (tmp->sprite_dir < 0 && map->p_angle >= M_PI / 6 && map->p_angle <= (M_PI * 2 - M_PI / 6))
			tmp->sprite_dir += 2 * M_PI;
		if (map->p_angle > (M_PI * 2 - M_PI / 6) && map->p_angle <= 7)
			tmp->sprite_dir += 2 * M_PI;
		tmp->sprite_dir -= map->p_angle;
		if (tmp->sprite_dir > -M_PI / 6 && tmp->sprite_dir < M_PI / 6)
			tmp->sprite_dist = sqrt(pow(map->x1 - tmp->sprite_x, 2) + pow(map->y1 - tmp->sprite_y, 2));
		else
			tmp->sprite_dist = -1;
		if (tmp->sprite_dist < 20)
			tmp->sprite_dist = -1;
		tmp = tmp->next;
	}
	sort_sprite(tmp);
	draw_sprite(map);
}

void 	sort_sprite(t_parser *map)
{
	t_sprite	*tmp;
	t_sprite	*data;

	data = map->sprite;
	tmp = map->sprite;
	while (tmp->next != NULL)
	{
		if ()
	}
}


int 	draw_sprite(t_parser *map)
{
	int		x;
	int 	y;
	int color;
	t_sprite	*tmp;

	tmp = map->sprite;
	while (tmp != NULL)
	{
		x = -1;
		tmp->h = 64 / tmp->sprite_dist * 600;
		tmp->size = tmp->h / map->tex4.w;
		tmp->x = map->width / 2 - (map->width / M_PI_3) * tmp->sprite_dir - tmp->h / 2;
		tmp->y = map->height / 2 - tmp->h / 2;
		while (++x < tmp->h && (x + tmp->x) < map->width)
		{
			y = -1;
			while (++y < tmp->h && (y + tmp->y) < map->height)
			{
				color = map->tex4.t_addr[(int) (y / tmp->size) * map->tex4.w + (int) (x / tmp->size) % map->tex4.h];
				if (color > 0)
					my_mlx_pixel_put(map, tmp->x + x, tmp->y + y, color);
			}
		}
		tmp = tmp->next;
	}
}
