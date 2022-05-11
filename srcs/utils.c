#include "../includes/fdf.h"

void check_malloc(void *ptr)
{
	if (!ptr)
	{
		free(ptr);
		ptr = NULL;
		ft_puterror("Malloc failed\n", -1);
	}
}

void zoom_in(t_program *m0, t_program *m1, t_program *mlx)
{
	if (mlx->is_z_above_20)
		mlx->zoom = (float)1;
	m0->x *= mlx->zoom;
	m0->y *= mlx->zoom;
	m0->z *= mlx->zoom / mlx->scale;
	m1->x *= mlx->zoom;
	m1->y *= mlx->zoom;
	m1->z *= mlx->zoom / mlx->scale;
}

void zoom_out(t_program *m0, t_program *m1, t_program *mlx)
{
	if (mlx->height >= 60 || mlx->width >= 60 || mlx->height <= -60 || mlx->width <= -60)
		mlx->zoom = 20;
	else if (mlx->height >= 30 || mlx->width >= 30 || mlx->height <= -30 || mlx->width <= -30)
		mlx->zoom = 5;
	else
		mlx->zoom = 2;
	m0->x /= mlx->zoom;
	m0->y /= mlx->zoom;
	m0->z /= mlx->zoom;
	m1->x /= mlx->zoom;
	m1->y /= mlx->zoom;
	m1->z /= mlx->zoom;
}

int apply_color(t_program m0, t_program m1, t_program *mlx)
{
	if (mlx->color > 0)
		return (mlx->color);
	if (m0.z || m1.z)
		return (0xfc031c);
	else
		return (0x4deeea);
}

void check_z_to_get_zoom(t_program *point, t_program *mlx)
{
	int i;
	int j;

	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			if (point->z <= -30 || point->z >= 30)
			{
				mlx->is_z_above_30 = 1;
				return;
			}
			if (point->z >= 20 || point->z <= -20)
			{
				mlx->is_z_above_20 = 1;
				return;
			}
			j++;
		}
		i++;
	}
}
