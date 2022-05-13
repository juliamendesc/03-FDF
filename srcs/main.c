/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:42:38 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/13 21:11:30 by julcarva         ###   ########.fr       */
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
		printf("%f\n", mlx->zoom);
		draw_map(mlx);
		events(mlx);
		mlx_loop(mlx->mlx_pointer);
	}
	ft_puterror("Usage ./fdf map.fdf\n", -1);
}
