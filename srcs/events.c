#include "../includes/fdf.h"

int key_pressed(int keycode, t_program *mlx)
{
	printf("key code: %d\n", keycode);
	if (keycode == 65307) // ESC linux. MAC é 53
	{
		mlx_destroy_window(mlx->mlx_pointer, mlx->mlx_win);
		free(mlx);
		exit(0);
	}
	return (0);
}

int mouse_clicked(int button, int x, int y, t_program *mlx)
{
	printf("button code: %d\t- coordinate (x: %d, y: %d)\n", button, x, y);
	if ((x >= 50 && x <= 150) && (y >= 50 && y <= 150))
		exit(0);
	return (0);
}
