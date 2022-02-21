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

int main(int argc, char **argv)
{
	t_program *mlx;
	t_coordinates *coord;

	mlx = (t_program *)malloc(sizeof(t_program));
	coord = (t_coordinates *)malloc(sizeof(t_coordinates));
	read_file(*++argv, coord);
	mlx->mlx_pointer = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_pointer, 1600, 1400, "FDF");
	mlx->img = mlx_new_image(mlx->mlx_pointer, 1600, 1400);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	coord->zoom = 20;
	draw_map(coord, mlx);
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->mlx_win, mlx->img, 0, 0);
	mlx_loop(mlx->mlx_pointer);
}
