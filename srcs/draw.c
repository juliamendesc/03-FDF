#include "../includes/fdf.h"

void isometric_projection(t_program *point, double angle)
{
	point->x = ((point->x - point->y) * cos(angle));
	point->y = ((point->x + point->y) * sin(angle) - point->z);
}

void my_mlx_pixel_put(t_program *data, int x, int y, int color)
{
	char *dst;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		if (data->color > 0)
			*(unsigned int *)dst = data->color;
		else
			*(unsigned int *)dst = color;
	}
}

void draw_line(t_program m0, t_program m1, t_program *mlx)
{
	float diff_x;
	float diff_y;
	float max;
	int color;

	set_parameters(&m0, mlx);
	set_parameters(&m1, mlx);
	diff_x = m1.x - m0.x;
	diff_y = m1.y - m0.y;
	max = MAX(ft_abs_float(diff_x), ft_abs_float(diff_y));
	diff_x /= max;
	diff_y /= max;
	color = 0;
	color = apply_color(m0, m1, mlx);
	while ((int)(m0.x - m1.x) || (int)(m0.y - m1.y))
	{
		my_mlx_pixel_put(mlx, m0.x, m0.y, color);
		m0.x += diff_x;
		m0.y += diff_y;
		if (m0.x < 0 || m0.x > WIDTH || m0.y < 0 || m0.y > HEIGHT)
			break;
	}
}

void set_parameters(t_program *point, t_program *mlx)
{
	point->x *= mlx->zoom;
	point->y *= mlx->zoom;
	point->z *= mlx->zoom / mlx->scale;
	point->x -= (mlx->width * mlx->zoom) / 2;
	point->y -= (mlx->height * mlx->zoom) / 2;
	// isometric_projection(point, mlx->angle);
	point->x += (WIDTH / 2) + mlx->adapt_x;
	point->y += (HEIGHT + mlx->height * mlx->zoom) / 2 + mlx->adapt_y;
}

void draw_map(t_program **coordinates_matrix, t_program *mlx)
{
	int x;
	int y;

	y = 0;
	while (coordinates_matrix[y])
	{
		x = 0;
		while (1)
		{
			if (coordinates_matrix[y + 1])
				draw_line(coordinates_matrix[y][x], coordinates_matrix[y + 1][x], mlx);
			if (!coordinates_matrix[y][x].is_last_matrix_point)
				draw_line(coordinates_matrix[y][x], coordinates_matrix[y][x + 1], mlx);
			if (coordinates_matrix[y][x].is_last_matrix_point)
				break;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->mlx_win, mlx->img, 0, 0);
}
