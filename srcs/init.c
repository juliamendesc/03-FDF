/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:41:49 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/15 01:18:33 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
	(*data)->adapt_x = WIDTH / 3;
	(*data)->adapt_y = HEIGHT / 3;
	(*data)->angle = 0.523599;
	(*data)->zoom = (WIDTH / HEIGHT) * 10;
	(*data)->scale = ft_min((*data)->width, (*data)->height);
}
