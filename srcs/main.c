#include "../includes/fdf.h"

int main(int argc, char **argv)
{
	t_program *mlx;
	t_program **matrix;

	if (argc == 2)
	{
		matrix = read_map(argv[1]);
		mlx = (t_program *)malloc(sizeof(t_program));
		if (!mlx)
			ft_puterror("Error: malloc failed", -1);
		init_program(&mlx, argv[1]);
		draw_map(matrix, mlx);
		mlx_key_hook(mlx->mlx_win, key_pressed, &mlx);
		mlx_loop(mlx->mlx_pointer);
	}
	ft_puterror("Error: wrong number of arguments.\n For calling, use ./fdf map.fdf\n", -1);
}
