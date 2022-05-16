/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:32:48 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/16 13:29:25 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_program	*mlx;

	if (argc == 2)
	{
		mlx = (t_program *)malloc(sizeof(t_program));
		if (!mlx)
			ft_puterror("Error: malloc failed", -1);
		mlx->matrix = read_map(argv[1]);
		init_program(&mlx, argv[1]);
		draw_map(mlx);
		events(mlx);
		mlx_loop(mlx->mlx_pointer);
	}
	ft_puterror("Usage ./fdf map.fdf", -1);
}

void	init_program(t_program **data, char *file_name)
{
	(*data)->mlx_pointer = mlx_init();
	(*data)->mlx_win = mlx_new_window((*data)->mlx_pointer, WIDTH, HEIGHT,
			"FDF");
	(*data)->img = mlx_new_image((*data)->mlx_pointer, WIDTH, HEIGHT);
	(*data)->addr = mlx_get_data_addr((*data)->img, &(*data)->bits_per_pixel,
			&(*data)->line_length, &(*data)->endian);
	(*data)->width = get_width(file_name);
	(*data)->height = get_height(file_name);
	(*data)->adapt_x = WIDTH - MENU_WIDTH / 2;
	(*data)->adapt_y = HEIGHT / 2;
	(*data)->angle = 0.523599;
	(*data)->zoom = ((WIDTH - MENU_WIDTH) / HEIGHT) * 10;
	(*data)->zoom_z = 5;
	(*data)->color = 0xFFFFFF;
	(*data)->is_isometric = 1;
}

void	events(t_program *fdf)
{
	while (1)
	{
		mlx_key_hook(fdf->mlx_win, key_press, fdf);
		mlx_hook(fdf->mlx_win, 17, 0, leave_window, fdf);
		mlx_loop(fdf->mlx_pointer);
	}
}
