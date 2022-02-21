#include "../includes/fdf.h"

void my_mlx_pixel_put(t_program *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int press_key(int key, void *data)
{
	printf("key: %d\n", key);
	return (0);
}

t_program *init_program(void)
{
	t_program *data;

	data = (t_program *)malloc(sizeof(t_program));
	if (!data)
		ft_puterror("Error: malloc failed at init program\n", -1);
	data->mlx_pointer = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_pointer, WIDTH, HEIGHT, "FDF");
	data->img = mlx_new_image(data->mlx_pointer, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (data);
}

t_coordinates *init_coordinates(void)
{
	t_coordinates *coord;

	coord = (t_coordinates *)malloc(sizeof(t_coordinates));
	if (!coord)
		ft_puterror("Error: malloc failed at init coordinates\n", -1);
	coord->z_matrix = NULL;
	coord->height = 0;
	coord->width = 0;
	coord->zoom = 20;
	return (coord);
}

int main(int argc, char **argv)
{
	t_program *mlx;
	t_coordinates *coord;

	mlx = init_program();
	coord = init_coordinates();
	read_file(*++argv, coord);
	coord->zoom = 20;
	draw_map(coord, mlx);
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->mlx_win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx_pointer);
}
