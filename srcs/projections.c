/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:42 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/16 11:41:03 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_projection(int keycode, t_program *fdf)
{
	if (keycode == 122) //z
		fdf->is_isometric = 1;
	else if (keycode == 120) //x
		fdf->is_isometric = 0;
	draw_map(fdf);
}

static void	isometric_projection(float *x, float *y, int z, t_program *fdf)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(fdf->angle);
	*y = -z + (previous_x + previous_y) * sin(fdf->angle);
}

t_program	project_point(t_program p, t_program *mlx)
{
	p.x *= mlx->zoom;
	p.y *= mlx->zoom;
	p.z *= mlx->zoom_z;
	p.x -= mlx->width * mlx->zoom / 2;
	p.y -= mlx->height * mlx->zoom / 2;
	if (mlx->is_isometric == 1)
		isometric_projection(&p.x, &p.y, p.z, mlx);
	p.x += mlx->adapt_x;
	p.y += mlx->adapt_y;
	return (p);
}
