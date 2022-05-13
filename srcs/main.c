#include "../includes/fdf.h"

int main(int argc, char **argv)
{
	t_program *mlx;

	if (argc == 2)
	{
		mlx = (t_program *)malloc(sizeof(t_program));
		if (!mlx)
			ft_puterror("Error: malloc failed", -1);
		mlx->matrix = read_map(argv[1]);
		init_program(&mlx, argv[1]);
		printf("%f\n", mlx->zoom);
		draw_map(mlx);
		events(mlx);
		mlx_loop(mlx->mlx_pointer);
	}
	ft_puterror("Error: wrong number of arguments.\n For calling, use ./fdf map.fdf\n", -1);
}
