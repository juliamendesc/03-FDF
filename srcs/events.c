#include "../includes/fdf.h"

void clear_mlx_data(void *ptr)
{
	t_program *data;

	if (!ptr)
		return;
	data = (t_program *)ptr;
	clear_matrix(data);
	if (data->img)
		mlx_destroy_image(data->img, data->mlx_pointer);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_pointer, data->mlx_win);
	if (data->mlx_pointer)
		free(data->mlx_pointer);
	free(data);
}

void clear_matrix(void *ptr)
{
	t_program *coord;
	int i;

	if (!ptr)
		return;
	coord = (t_program *)ptr;
	if (coord->z_matrix)
	{
		i = 0;
		while (i < coord->height)
		{
			free(coord->z_matrix[i]);
			i++;
		}
		free(coord->z_matrix);
		coord->z_matrix = NULL;
	}
	free(coord);
}

int key_pressed(int keycode)
{
	printf("key code: %d\n", keycode);
	if (keycode == 53) // ESC linux. MAC é 53
	{
		exit(0);
	}
	return (0);
}
