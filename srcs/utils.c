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

int apply_color(t_program m0, t_program m1)
{
	if (m0.z > 0 || m1.z > 0)
		return (0xe08309);
	if (m0.z < 0 || m1.z < 0)
		return (0x3256a8);
	if (m1.z != m0.z)
		return (0xEC4B27);
	else
		return (0xffffff);
}

void reset_window(t_program *fdf)
{
	mlx_clear_window(fdf->mlx_pointer, fdf->mlx_win);
}
