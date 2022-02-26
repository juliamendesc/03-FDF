#include "../includes/fdf.h"

int main(int argc, char **argv)
{
	t_program *mlx;

	if (argc == 2)
	{
		mlx = init_program();
		read_file(argv[1], mlx);
		draw_map(mlx);
		mlx_put_image_to_window(mlx->mlx_pointer, mlx->mlx_win, mlx->img, 100, 100);
		mlx_key_hook(mlx->mlx_win, key_pressed, &mlx);
		// mlx_mouse_hook(mlx->mlx_win, mouse_clicked, &mlx);
		mlx_loop(mlx->mlx_pointer);
	}
	ft_puterror("Error: wrong number of arguments\n", -1);
}
