/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:42:43 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/13 21:14:36 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		free(ptr);
		ptr = NULL;
		ft_puterror("Malloc failed\n", -1);
	}
}

int	apply_color(t_program m0, t_program m1)
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

void	reset_window(t_program *fdf)
{
	mlx_clear_window(fdf->mlx_pointer, fdf->mlx_win);
}

void	my_mlx_pixel_put(t_program *data, int x, int y, int color)
{
	char	*pixel;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		pixel = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}
