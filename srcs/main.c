/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 10:32:48 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/14 12:00:03 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_program *mlx;

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

void	events(t_program *fdf)
{
	while (1)
	{
		mlx_key_hook(fdf->mlx_win, key_press, fdf);
		mlx_loop(fdf->mlx_pointer);
	}
}
