#include "../includes/fdf.h"

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
	data->z_matrix = NULL;
	data->height = 0;
	data->width = -1;
	data->zoom = 25;
	return (data);
}

t_point apply_zoom(t_point m, t_program *coord)
{

	m.x = m.x * coord->zoom;
	m.y = m.y * coord->zoom;
	m.z = m.z * coord->zoom;
	return (m);
}

t_point apply_color(t_point m)
{
	if (m.z < 0)
		m.color = 0xFF0000FF;
	else if (m.z > 0)
		m.color = 0x00FF00FF;
	else
		m.color = 0xFFFFFFFF;
	return (m);
}
