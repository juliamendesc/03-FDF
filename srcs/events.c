/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:42 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/17 20:21:04 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_press(int keycode, void *param)
{
	t_program	*fdf;

	fdf = (t_program *)param;
	if (keycode == 53 || keycode == 65307)
		exit(0);
	else if (keycode == 69 || keycode == 78 \
		|| keycode == 24 || keycode == 27)
		zoom(keycode, fdf);
	else if (keycode == 12 || keycode == 13)
		flatten_z(keycode, fdf);
	else if (keycode == 126 || keycode == 125 \
		|| keycode == 123 || keycode == 124)
		move(keycode, fdf);
	else if (keycode == 0 || keycode == 1)
		rotate(keycode, fdf);
	else if (keycode == 6 || keycode == 7)
		change_projection(keycode, fdf);
	else if (keycode == 36)
		reset_view(keycode, &fdf);
	return (0);
}

void	zoom(int keycode, t_program *fdf)
{
	if (keycode == 69 || keycode == 24)
		fdf->zoom += 1;
	else if (keycode == 78 || keycode == 27)
		fdf->zoom -= 1;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	draw_map(fdf);
}

void	move(int keycode, t_program *fdf)
{
	if (keycode == 126)
		fdf->adapt_y += 10;
	else if (keycode == 124)
		fdf->adapt_x += 10;
	else if (keycode == 125)
		fdf->adapt_y -= 10;
	else if (keycode == 123)
		fdf->adapt_x -= 10;
	draw_map(fdf);
}

void	flatten_z(int keycode, t_program *fdf)
{
	if (keycode == 12)
		fdf->zoom_z++;
	else if (keycode == 13)
		fdf->zoom_z--;
	draw_map(fdf);
}

void	rotate(int keycode, t_program *fdf)
{
	if (keycode == 1)
		fdf->angle += 0.05;
	else if (keycode == 0)
		fdf->angle -= 0.05;
	draw_map(fdf);
}
