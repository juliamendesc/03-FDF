/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:42 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/16 11:52:23 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int key_press(int keycode, void *param)
{
	t_program *fdf;

	fdf = (t_program *)param;
	if (keycode == 53 || keycode == 65307)
		exit(0);
	else if (keycode == 69 || keycode == 43 || keycode == 78 || keycode == 45)
		zoom(keycode, fdf);
	else if (keycode == 113 || keycode == 119)
		flatten_z(keycode, fdf);
	else if (keycode == 65362 || keycode == 126 || keycode == 65361 || keycode == 125 || keycode == 65363 || keycode == 123 || keycode == 65364 || keycode == 124)
		move(keycode, fdf);
	else if (keycode == 97 || keycode == 115)
		rotate(keycode ,fdf);
	else if (keycode == 122 || keycode == 120)
		change_projection(keycode, fdf);
	else if (keycode == 36 || keycode == 65293)
		reset_view(keycode, &fdf);
	return (0);
}

void zoom(int keycode, t_program *fdf)
{
	if (keycode == 69 || keycode == 43)
		fdf->zoom += 1;
	else if (keycode == 78 || keycode == 45)
		fdf->zoom -= 1;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	draw_map(fdf);
}

void move(int keycode, t_program *fdf)
{
	if (keycode == 65362 || keycode == 126)
		fdf->adapt_y += 10;
	else if (keycode == 65361 || keycode == 125)
		fdf->adapt_x += 10;
	else if (keycode == 65364 || keycode == 123)
		fdf->adapt_y -= 10;
	else if (keycode == 65363 || keycode == 124)
		fdf->adapt_x -= 10;
	draw_map(fdf);
}

void flatten_z(int keycode, t_program *fdf)
{
	if (keycode == 113) //q
		fdf->zoom_z++;
	else if (keycode == 119) //w
		fdf->zoom_z--;
	draw_map(fdf);
}

void	rotate(int keycode, t_program *fdf)
{
	if (keycode == 115) //s
		fdf->angle += 0.05;
	else if (keycode == 97) //a
		fdf->angle -= 0.05;
	draw_map(fdf);
}
