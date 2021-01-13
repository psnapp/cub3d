
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
		sort_sprite(map, tmp);
		draw_sprite(map, tmp);
		tmp = tmp->next;
	}
}



//{
//	t_sprite *tmp;
//	int s_h;
//	double coef;
//
//	tmp = map->sprite;
//	while (tmp != NULL)
//	{
//		tmp->sprite_dist = sqrt(pow(tmp->sprite_x - map->x1, 2) +
//								pow(tmp->sprite_y - map->y1, 2));
//		s_h = (int) ((((map->width / 2.0) / tan(M_PI_6)) / (tmp->sprite_dist * CUB_SIZE) *
//					  map->height));
//		map->sprite_dir = atan2(tmp->sprite_y - map->y1, tmp->sprite_x - map->x1);
//		coef = 64.0 / s_h;
//		while (map->sprite_dir - map->p_angle > M_PI)
//			map->sprite_dir -= 2 * M_PI;
//		while (map->sprite_dir - map->p_angle < -M_PI)
//			map->sprite_dir += 2 * M_PI;
//		map->sprite_dir = map->sprite_dir - map->p_angle;
//		map->sprite_x = map->sprite_dir * (map->width / 2) /
//						(M_PI / 6) + map->width / 2 - s_h / 2;
//		map->sprite_y = map->height / 2 - s_h / 2;
//		draw_sprite(map, tmp, coef, s_h);
//		tmp = tmp->next;
//	}
//}


//	int h;
//	int v;
//	t_sprite	*tmp;
//
//	tmp = map->sprite;
//	while (tmp != NULL)
//	{
//		tmp->sprite_dist = sqrt(pow(tmp->sprite_x - map->x1, 2) + pow(tmp->sprite_y - map->y1, 2));
//		tmp->sprite_dir = atan2(tmp->sprite_y - map->y1, tmp->sprite_x - map->x1);
//		while (tmp->sprite_dir - map->p_angle > M_PI)
//			tmp->sprite_dir -= 2 * M_PI;
//		while (tmp->sprite_dir - map->p_angle < -M_PI)
//			tmp->sprite_dir += 2 * M_PI;
//		tmp->size = map->height * CUB_SIZE / tmp->sprite_dist;
//		h = (tmp->sprite_dir - map->p_angle) * map->width / M_PI_3 + map->width / 2 - tmp->size / 2;
//		v = map->height / 2 - tmp->size / 2;
//		draw_sprite(map, tmp, h, v);
//		tmp = tmp->next;
//	}
//}

int 	draw_sprite(t_parser *map, t_sprite *tmp)
{
	int		x;
	int 	y;
	int color;

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
}
