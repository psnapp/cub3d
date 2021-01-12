
#include "cub3d.h"

int 	texture_mlx(t_parser *map)
{
	map->tex.t_img = mlx_xpm_file_to_image(map->mlx, map->str_so, &map->tex.w, &map->tex.h);
	map->tex.t_addr = (int *) mlx_get_data_addr(map->tex.t_img, &map->tex.t_bits_per_pixel, &map->tex.t_line_length,
											 &map->tex.t_endian);

	map->tex1.t_img = mlx_xpm_file_to_image(map->mlx, map->str_no, &map->tex1.w, &map->tex1.h);
	map->tex1.t_addr = (int *) mlx_get_data_addr(map->tex1.t_img, &map->tex1.t_bits_per_pixel, &map->tex1.t_line_length, &map->tex1.t_endian);

	map->tex2.t_img = mlx_xpm_file_to_image(map->mlx, map->str_we, &map->tex2.w, &map->tex2.h);
	map->tex2.t_addr = (int *) mlx_get_data_addr(map->tex2.t_img, &map->tex2.t_bits_per_pixel,
													 &map->tex2.t_line_length, &map->tex2.t_endian);

	map->tex3.t_img = mlx_xpm_file_to_image(map->mlx, map->str_ea, &map->tex3.w, &map->tex3.h);
	map->tex3.t_addr = (int *) mlx_get_data_addr(map->tex3.t_img, &map->tex3.t_bits_per_pixel,
													 &map->tex3.t_line_length, &map->tex3.t_endian);

	map->tex4.t_img = mlx_xpm_file_to_image(map->mlx, map->str_s, &map->tex4.w, &map->tex4.h);
	map->tex4.t_addr = (int *) mlx_get_data_addr(map->tex4.t_img, &map->tex4.t_bits_per_pixel, &map->tex4.t_line_length,
												&map->tex4.t_endian);
}
