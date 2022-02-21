#include "../includes/fdf.h"

void isometric_projection(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) + z;
}

void draw_line(t_point m0, t_point m1, t_coordinates *coord, t_program *img)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	m0.z = coord->z_matrix[(int)m0.y][(int)m1.x];
	m1.z = coord->z_matrix[(int)m1.y][(int)m1.x];

	m0.x *= coord->zoom;
	m0.y *= coord->zoom;
	m1.x *= coord->zoom;
	m1.y *= coord->zoom;

	if (m0.z != 0)
		coord->color = 0xE80C0C;
	else
		coord->color = 0xFFFFFFFF;
	x_step = m1.x - m0.x;
	y_step = m1.y - m0.y;
	// isometric_projection(&x, &y, z);
	// isometric_projection(&x1, &y1, z1);
	max = MAX(ft_abs_float(x_step), ft_abs_float(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(m0.x - m1.x) || (int)(m0.y - m1.y))
	{
		my_mlx_pixel_put(img, m0.x, m0.y, coord->color);
		m0.x += x_step;
		m0.y += y_step;
	}
}

void draw_map(t_coordinates *coord, t_program *img)
{
	t_point m0;
	t_point m1;

	m0.y = 0;
	while (m0.y < coord->height)
	{
		m0.x = 0;
		while (m0.x < coord->width)
		{
			if (m0.x < coord->width - 1)
			{
				m1.x = m0.x + 1;
				m1.y = m0.y;
				draw_line(m0, m1, coord, img);
			}
			if (m0.y < coord->height - 1)
			{
				m1.x = m0.x;
				m1.y = m0.y + 1;
				draw_line(m0, m1, coord, img);
			}
			m0.x++;
		}
		m0.y++;
	}
}
