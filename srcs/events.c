/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:42 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/18 12:44:41 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_press(int keycode, void *param)
{
	t_program	*fdf;

	fdf = (t_program *)param;
	printf("keycode: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit(0);
	else if (keycode == 69 || keycode == 78 \
		|| keycode == 24 || keycode == 27 || keycode == 43 \
		|| keycode == 45 )
		zoom(keycode, fdf);
	else if (keycode == 12 || keycode == 13 || keycode == 113 \
	|| keycode == 119)
		flatten_z(keycode, fdf);
	else if (keycode == 126 || keycode == 125 \
		|| keycode == 123 || keycode == 124 || keycode == 65362 \
		|| keycode == 65364 || keycode == 65361 || keycode == 65363)
		move(keycode, fdf);
	else if (keycode == 0 || keycode == 1 || keycode == 97 || keycode == 115)
		rotate(keycode, fdf);
	else if (keycode == 6 || keycode == 7 || keycode == 120 || keycode == 122)
		change_projection(keycode, fdf);
	else if (keycode == 36 || keycode == 65293)
		reset_view(keycode, &fdf);
	return (0);
}

void	zoom(int keycode, t_program *fdf)
{
	if (keycode == 69 || keycode == 24 || keycode == 43)
		fdf->zoom += 1;
	else if (keycode == 78 || keycode == 27 || keycode == 45)
		fdf->zoom -= 1;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	draw_map(fdf);
}

void	move(int keycode, t_program *fdf)
{
	if (keycode == 126 || keycode == 65362)
		fdf->adapt_y += 10;
	else if (keycode == 124 || keycode == 65363)
		fdf->adapt_x += 10;
	else if (keycode == 125 || keycode == 65364)
		fdf->adapt_y -= 10;
	else if (keycode == 123 || keycode == 65361)
		fdf->adapt_x -= 10;
	draw_map(fdf);
}

void	flatten_z(int keycode, t_program *fdf)
{
	if (keycode == 12 || keycode == 113)
		fdf->zoom_z++;
	else if (keycode == 13 || keycode == 119)
		fdf->zoom_z--;
	draw_map(fdf);
}

void	rotate(int keycode, t_program *fdf)
{
	if (keycode == 1 || keycode == 97)
		fdf->angle += 0.05;
	else if (keycode == 0 || keycode == 115)
		fdf->angle -= 0.05;
	draw_map(fdf);
}
