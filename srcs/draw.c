#include "../includes/fdf.h"

void isometric_projection(t_point *m)
{
	m->x = (m->x - m->y) * cos(0.8);
	m->y = (m->x + m->y) * sin(0.8) + m->z;
}

t_point apply_zoom(t_point m, t_coordinates *coord)
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

void draw_line(t_point m0, t_point m1, t_coordinates *coord, t_program *img)
{
	float x_step;
	float y_step;
	int max;

	m0.z = coord->z_matrix[(int)m0.y][(int)m1.x];
	m1.z = coord->z_matrix[(int)m1.y][(int)m1.x];

	m0 = apply_zoom(m0, coord);
	m1 = apply_zoom(m1, coord);

	m0 = apply_color(m0);
	m1 = apply_color(m1);
	x_step = m1.x - m0.x;
	y_step = m1.y - m0.y;
	// isometric_projection(&m1);
	// isometric_projection(&m0);
	max = MAX(ft_abs_float(x_step), ft_abs_float(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(m0.x - m1.x) || (int)(m0.y - m1.y))
	{
		my_mlx_pixel_put(img, m0.x, m0.y, m0.color);
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
