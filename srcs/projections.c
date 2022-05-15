/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:42 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/16 00:34:46 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void rotate_x_axis(float *y, float *z, t_program *fdf)
{
	float previous_y;

	previous_y = *y;
	*y = previous_y * cos(fdf->alpha) + *z * sin(fdf->alpha);
	*z = -previous_y * sin(fdf->alpha) + *z * cos(fdf->alpha);
}

static void rotate_y_axis(float *x, float *z, t_program *fdf)
{
	float previous_x;

	previous_x = *x;
	*x = previous_x * cos(fdf->beta) + *z * sin(fdf->beta);
	*z = -previous_x * sin(fdf->beta) + *z * cos(fdf->beta);
}

static void rotate_z_axis(float *x, float *y, t_program *fdf)
{
	float previous_x;
	float previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(fdf->gamma) + previous_y * sin(fdf->gamma);
	*y = -previous_x * sin(fdf->gamma) + previous_y * cos(fdf->gamma);
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
	isometric_projection(&p.x, &p.y, p.z, mlx);
	rotate_x_axis(&p.y, &p.z, mlx);
	rotate_y_axis(&p.x, &p.z, mlx);
	rotate_z_axis(&p.x, &p.y, mlx);
	p.x += mlx->adapt_x;
	p.y += mlx->adapt_y;
	return (p);
}
