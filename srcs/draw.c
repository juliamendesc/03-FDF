#include "../includes/fdf.h"

void isometric_projection(t_point *m)
{
	m->x = (m->x - m->y) * cos(0.53);
	m->y = (m->x + m->y) * sin(0.53) + m->z;
	m->x += WIDTH / 3;
	m->y += 50;
}

void my_mlx_pixel_put(t_program *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_line(t_point m0, t_point m1, t_program *mlx)
{
	float diff_x;
	float diff_y;
	int max;

	m0.z = mlx->z_matrix[(int)m0.y][(int)m1.x];
	m1.z = mlx->z_matrix[(int)m1.y][(int)m1.x];
	m0 = apply_zoom(m0, mlx);
	m1 = apply_zoom(m1, mlx);
	m0 = apply_color(m0);
	m1 = apply_color(m1);
	isometric_projection(&m1);
	isometric_projection(&m0);
	diff_x = m1.x - m0.x;
	diff_y = m1.y - m0.y;
	max = MAX(ft_abs_float(diff_x), ft_abs_float(diff_y));
	diff_x /= max;
	diff_y /= max;
	while ((int)(m0.x - m1.x) || (int)(m0.y - m1.y))
	{
		my_mlx_pixel_put(mlx, m0.x, m0.y, m0.color);
		m0.x += diff_x;
		m0.y += diff_y;
	}
}

void draw_map(t_program *mlx)
{
	t_point m0;
	t_point m1;

	m0.y = 0;
	while (m0.y < mlx->height)
	{
		m0.x = 0;
		while (m0.x < mlx->width)
		{
			if (m0.x < mlx->width - 1)
			{
				m1.x = m0.x + 1;
				m1.y = m0.y;
				draw_line(m0, m1, mlx);
			}
			if (m0.y < mlx->height - 1)
			{
				m1.x = m0.x;
				m1.y = m0.y + 1;
				draw_line(m0, m1, mlx);
			}
			m0.x++;
		}
		m0.y++;
	}
}
