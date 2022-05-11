#include "../includes/fdf.h"

static void isometric_projection(float *x, float *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void my_mlx_pixel_put(t_program *data, int x, int y, int color)
{
	char *pixel;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		if (data->color > 0)
			*(unsigned int *)pixel = data->color;
		else
			*(unsigned int *)pixel = color;
	}
}

void draw_line(t_program m0, t_program m1, t_program *mlx)
{
	float diff_x;
	float diff_y;
	float max;
	int color;
	t_program m;

	diff_x = m1.x - m0.x;
	diff_y = m1.y - m0.y;
	max = MAX(ft_abs_float(diff_x), ft_abs_float(diff_y));
	diff_x /= max;
	diff_y /= max;
	color = 0;
	color = apply_color(m0, m1, mlx);
	m = m0;
	while ((int)(m.x - m1.x) || (int)(m.y - m1.y))
	{
		my_mlx_pixel_put(mlx, m.x, m.y, color);
		m.x += diff_x;
		m.y += diff_y;
	}
}

t_program project(t_program p, t_program *mlx)
{
	p.x *= mlx->zoom;
	p.y *= mlx->zoom;
	p.z *= mlx->zoom / mlx->scale;
	p.x -= mlx->width * mlx->zoom / 2;
	p.y -= mlx->height * mlx->zoom / 3;
	isometric_projection(&p.x, &p.y, p.z);
	p.x += (WIDTH) / 2;
	p.y += (HEIGHT + mlx->height * mlx->zoom) / 3;
	return (p);
}

void draw_map(t_program **coordinates_matrix, t_program *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			if (y != mlx->height - 1)
				draw_line(project(coordinates_matrix[y][x], mlx), project(coordinates_matrix[y + 1][x], mlx), mlx);
			if (x != mlx->width - 1)
				draw_line(project(coordinates_matrix[y][x], mlx), project(coordinates_matrix[y][x + 1], mlx), mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->mlx_win, mlx->img, 0, 0);
}
