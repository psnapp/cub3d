/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 11:36:56 by psnapp            #+#    #+#             */
/*   Updated: 2020/12/13 17:05:12 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define PIX 64
# define M_PI_3 M_PI/3
# define M_PI_6 M_PI/6
# define CUB_SIZE 64
# define FOV M_PI/3
# define SPEED 1
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include "minilibx_mms_20200219/mlx.h"
#include <math.h>

typedef struct s_text
{
	int 	*t_addr;
	int		t_bits_per_pixel;
	int		t_line_length;
	int		t_endian;
	void 	*t_img;
	int 	w;
	int 	h;
}			t_text;

typedef struct s_sprite
{
	struct s_sprite	*next;
	int		sprite_x;
	int 	sprite_y;
	double	sprite_dist;
}			t_sprite;

typedef struct s_map
{
	char	**map;
	int		count;
	int		fd;
	int		width;
	int		height;


	char		flag;
	char	*str_s;
	char	*str_ea;
	char	*str_we;
	char	*str_so;
	char	*str_no;
	double 	ax;
	double 	by;
	double	dist1;

	double	sprite_dir;
	int 	sprite_x;
	int 	sprite_y;

	int		f_col;
	int		c_col;

	void 	*mlx;
	void	*win;
	void	*img;

	double		x;
	double		y;
	double		x1;
	double		y1;

	char	*addr;
   	int		bits_per_pixel;
    int		line_length;
    int		endian;

	double	p_angle;

	int key_123;
	int 	key_s;
	int 	key_w;
	int		key_124;
	int		key_right;
	int 	key_left;
	int 	key_ex;

	t_text	tex;
	t_text	tex1;
	t_text	tex2;
	t_text	tex3;
	t_text	tex4;

	t_sprite	*sprite;

}				t_parser;

int		main(int argc, char **argv);
int		ft_valid_args(int argc, char **argv);
int		parser(t_parser *map);
int     parse_wh(t_parser *map, char *line);
int		parse_n(t_parser *map, char *line);
int		parse_so(t_parser *map, char *line);
int		parse_w(t_parser *map, char *line);
int		parse_e(t_parser *map, char *line);
int		parse_s(t_parser *map, char *line);
int     parse_cf(t_parser *map, char *line, char flag);
int			ft_rgb(t_parser *map, int *rgb, char flag);
int		parse_map(t_parser *map, char *line);
char		**ft_add_line_to_array(t_parser *map, char *line);
char		**ft_add_line_to_array(t_parser *map, char *line);
void	draw(t_parser *map, int x0, int y0, int s);
void		ft_map_2d(t_parser *map);
void	ft_player_2d(t_parser *map);
void	draw1(t_parser *map, int x0, int y0, int s);
int		key_press(t_parser *map);
void            my_mlx_pixel_put(t_parser *map, int x, int y, int color);
void	draw_all(t_parser *map);
void	ft_init_struct(t_parser *map);
void	dir_player(t_parser *map);
void	raycasting(t_parser *map);
double	vertical_raycasting(t_parser *map, double angle);
double	horizontal_raycasting(t_parser *map, double angle);
void	draw_walls(t_parser *map, int i, double s, double start_angle);
int  press_manager(int key, t_parser *map);
int releas_manager(int key, t_parser *map);
int	loop_manager(t_parser *map);
int 	texture_mlx(t_parser *map);
int 	tex(t_parser *map, double coef, int draw_start, int start);
void 	sprite(t_parser *map);
t_sprite 	*new_sprite(t_parser *map, int i, int j);
int 	calc_sprite(t_parser *map);
int 	draw_sprite(t_parser *map, t_sprite *tmp, double coef, int s_h);

#endif