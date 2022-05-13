/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:42 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/13 22:14:14 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_press(int keycode, void *param)
{
	t_program	*fdf;

	fdf = (t_program *)param;
	printf("key code: %d\n", keycode);
	if (keycode == 53 || keycode == 65307)
		exit(0);
	else if (keycode == 69 || keycode == 43 || keycode == 78 || keycode == 45)
		zoom(keycode, fdf);
	else if (keycode == 36 || keycode == 65293)
	{
		fdf->zoom = 20;
		fdf->angle = 0.8;
	}
	return (0);
}

int	leave(void)
{
	exit(0);
}

void	zoom(int keycode, t_program *fdf)
{
	if (keycode == 69 || keycode == 43)
	{
		fdf->zoom++;
	}
	else if (keycode == 78 || keycode == 45)
		fdf->zoom--;
	if (fdf->zoom < 1)
		fdf->zoom = 2;
	draw_map(fdf);
}

void	move(int keycode, t_program *data)
{
	if (keycode == 65362 || keycode == 126)
		data->adapt_y -= 10;
	else if (keycode == 65361 || keycode == 125)
		data->adapt_y += 10;
	else if (keycode == 65364 || keycode == 123)
		data->adapt_x -= 10;
	else if (keycode == 65363 || keycode == 124)
		data->adapt_x += 10;
	reset_window(data);
}

void	events(t_program *fdf)
{
	while (1)
	{
		mlx_key_hook(fdf->mlx_win, key_press, fdf);
		mlx_hook(fdf->mlx_win, 17, 0, leave, fdf);
		mlx_loop(fdf->mlx_pointer);
	}
}
