/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcarva <julcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:42:02 by julcarva          #+#    #+#             */
/*   Updated: 2022/05/16 11:49:30 by julcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080
# define HEXADECIMAL_BASE "0123456789abcdef"

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line_fdf.h"

typedef struct s_program
{
	int					is_isometric;

	float				x;
	float				y;
	float				z;
	float				zoom;
	int					zoom_z;
	int					color;
	int					adapt_x;
	int					adapt_y;
	int					width;
	int					height;
	double				angle;
	void				*mlx_pointer;
	void				*mlx_win;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	struct s_program	**matrix;
}	t_program;

t_program	project_point(t_program p, t_program *mlx);
t_program	**create_coordinates_matrix(char *file_name);
t_program	**read_map(char *file_name);
int			get_height(char *file_name);
int			get_width(char *file_name);
int			fill_matrix_lines(char *line, t_program **map_matrix, int y);
int			apply_color(t_program m0, t_program m1);
void		draw_line(t_program m0, t_program m1, t_program *mlx);
void		draw_map(t_program *mlx);
void		init_program(t_program **data, char *file_name);
int			key_press(int keycode, void *param);
int			leave_window(void);
void		change_projection(int keycode, t_program *fdf);
void		reset_view(int keycode, t_program **fdf);
void		events(t_program *fdf);
void		zoom(int keycode, t_program *fdf);
void		move(int keycode, t_program *data);
void		flatten_z(int keycode, t_program *data);
void		rotate(int keycode, t_program *fdf);
void		my_mlx_pixel_put(t_program *data, int x, int y, int color);
void		check_malloc(void *ptr);

#endif
