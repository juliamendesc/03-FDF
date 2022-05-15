/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:42 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/16 00:33:03 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int key_press(int keycode, void *param)
{
	t_program *fdf;

	fdf = (t_program *)param;
	printf("keycode: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit(0);
	else if (keycode == 69 || keycode == 43 || keycode == 78 || keycode == 45)
		zoom(keycode, fdf);
	else if (keycode == 109 || keycode == 110)
		flatten_z(keycode, fdf);
	else if (keycode == 65362 || keycode == 126 || keycode == 65361 || keycode == 125 || keycode == 65363 || keycode == 123 || keycode == 65364 || keycode == 124)
		move(keycode, fdf);
	else if (keycode == 113 || keycode == 97 || keycode == 119 || keycode == 115 || keycode == 101 || keycode == 100)
		rotate(keycode ,fdf);
	// else if (keycode == 36 || keycode == 65293)
	// 	fdf->zoom = 20;
	// fdf->angle = 0.8;
	return (0);
}

int leave_window(void)
{
	exit(0);
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

void move(int keycode, t_program *data)
{
	if (keycode == 65362 || keycode == 126)
		data->adapt_y += 10;
	else if (keycode == 65361 || keycode == 125)
		data->adapt_x += 10;
	else if (keycode == 65364 || keycode == 123)
		data->adapt_y -= 10;
	else if (keycode == 65363 || keycode == 124)
		data->adapt_x -= 10;
	draw_map(data);
}

void flatten_z(int keycode, t_program *data)
{
	if (keycode == 109)
		data->zoom_z++;
	else if (keycode == 110)
		data->zoom_z--;
	draw_map(data);
}

void	rotate(int keycode, t_program *fdf)
{
	if (keycode == 113)
		fdf->alpha += 0.05;
	else if (keycode == 97)
		fdf->alpha -= 0.05;
	else if (keycode == 119)
		fdf->beta -= 0.05;
	else if (keycode == 115 )
		fdf->beta += 0.05;
	else if (keycode == 101)
		fdf->gamma += 0.05;
	else if (keycode == 100 )
		fdf->gamma -= 0.05;
	draw_map(fdf);
}
