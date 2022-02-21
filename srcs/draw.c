#include "../includes/fdf.h"

void isometric_projection(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) + z;
}

void draw_line(float x, float y, float x1, float y1, t_coordinates *coord, t_program *img)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

	z = coord->z_matrix[(int)y][(int)x];
	z1 = coord->z_matrix[(int)y1][(int)x1];

	x *= coord->zoom;
	y *= coord->zoom;
	x1 *= coord->zoom;
	y1 *= coord->zoom;

	if (z != 0)
		coord->color = 0xE80C0C;
	else
		coord->color = 0xFFFFFFFF;
	x_step = x1 - x;
	y_step = y1 - y;
	// isometric_projection(&x, &y, z);
	// isometric_projection(&x1, &y1, z1);
	max = MAX(ft_abs_float(x_step), ft_abs_float(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(img, x, y, coord->color);
		x += x_step;
		y += y_step;
		printf("INSIDE LOOP x=%f, y=%f, x1=%f, y1=%f\n", x, y, x1, y1);
	}
	printf("AFTER LINE DRAW x=%f, y=%f, x1=%f, y1=%f\n", x, y, x1, y1);
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
				draw_line(m0.x, m0.y, m1.x, m1.y, coord, img);
			}
			if (m0.y < coord->height - 1)
			{
				m1.x = m0.x;
				m1.y = m0.y + 1;
				draw_line(m0.x, m0.y, m1.x, m1.y, coord, img);
			}
			m0.x++;
		}
		m0.y++;
	}
}
