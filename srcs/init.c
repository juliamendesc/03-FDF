#include "../includes/fdf.h"

void init_program(t_program **data, char *file_name)
{
	(*data)->mlx_pointer = mlx_init();
	(*data)->mlx_win = mlx_new_window((*data)->mlx_pointer, WIDTH, HEIGHT, "FDF");
	(*data)->img = mlx_new_image((*data)->mlx_pointer, WIDTH, HEIGHT);
	(*data)->addr = mlx_get_data_addr((*data)->img, &(*data)->bits_per_pixel, &(*data)->line_length, &(*data)->endian);
	(*data)->z_matrix = NULL;
	(*data)->adapt_x = WIDTH / 3;
	(*data)->adapt_y = HEIGHT / 3;
	(*data)->angle = 0.523599;
	(*data)->width = get_width(file_name);
	(*data)->height = get_height(file_name);
	(*data)->zoom = FT_MIN(WIDTH / (*data)->width / 2,
												 HEIGHT / (*data)->height / 2);
	(*data)->diagonal = ft_abs(sqrt(pow((*data)->height, 2) + pow((*data)->width, 2)));
	(*data)->scale_height = WIDTH / (*data)->height;
	(*data)->scale_width = HEIGHT / (*data)->width;
	(*data)->scale = ft_min((*data)->width, (*data)->height);
	(*data)->is_z_above_30 = 0;
	(*data)->is_z_above_20 = 0;
}
