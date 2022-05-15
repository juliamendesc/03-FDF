/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:57 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/16 00:39:46 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_background(t_program *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH)
			image[i] = 0x222222;
		i++;
	}
}

void	draw_line(t_program m0, t_program m1, t_program *mlx)
{
	float		diff_x;
	float		diff_y;
	float		max;
	t_program	m;

	diff_x = m1.x - m0.x;
	diff_y = m1.y - m0.y;
	max = ft_max(ft_abs_float(diff_x), ft_abs_float(diff_y));
	diff_x /= max;
	diff_y /= max;
	m = m0;
	while ((int)(m.x - m1.x) || (int)(m.y - m1.y))
	{
		my_mlx_pixel_put(mlx, m.x, m.y, apply_color(m0, m1));
		m.x += diff_x;
		m.y += diff_y;
	}
}

void	draw_map(t_program *mlx)
{
	int	x;
	int	y;

	draw_background(mlx);
	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			if (y != mlx->height - 1)
				draw_line(project_point(mlx->matrix[y][x], mlx),
					project_point(mlx->matrix[y + 1][x], mlx), mlx);
			if (x != mlx->width - 1)
				draw_line(project_point(mlx->matrix[y][x], mlx),
					project_point(mlx->matrix[y][x + 1], mlx), mlx);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->mlx_pointer, mlx->mlx_win, mlx->img, 0, 0);
}
