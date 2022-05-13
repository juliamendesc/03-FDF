#ifndef FDF_H

#define FDF_H

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line_fdf.h"

#define MAX(a, b) (a > b ? a : b)
#define WIDTH 1280
#define HEIGHT 720
#define HEXADECIMAL_BASE "0123456789abcdef"
#define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
#define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))
typedef struct s_program
{
	/* POINT */
	float x;
	float y;
	float z;
	int color;

	/* WINDOW */
	void *mlx_pointer;
	void *mlx_win;

	/* IMAGE AND DRAW */
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;

	/* ISO PROJECTION MUTATORS */
	int diagonal;
	float scale_height;
	float scale_width;
	float scale;
	double angle;
	int adapt_x;
	int adapt_y;
	float zoom;

	/* COORDINATES */
	int width;
	int height;
	int **z_matrix;
	struct s_program **matrix;
} t_program;

/* INIT STRUCTS */
void init_program(t_program **data, char *file_name);
int apply_color(t_program m0, t_program m1);

/* FETCHING COORDINATES */
int get_height(char *file_name);
int get_width(char *file_name);
int fill_matrix_lines(char *line, t_program **map_matrix, int y);
t_program **create_coordinates_matrix(char *file_name);
t_program **read_map(char *file_name);

/* HOOKS AND UTILS */
int key_press(int keycode, void *param);
int leave(void);
void reset_window(t_program *fdf);
void check_malloc(void *ptr);
void events(t_program *fdf);
void move(int keycode, t_program *data);
void zoom(int keycode, t_program *fdf);

/* DRAWING */
void my_mlx_pixel_put(t_program *data, int x, int y, int color);
void draw_line(t_program m0, t_program m1, t_program *mlx);
void draw_map(t_program *mlx);
void clear_mlx_data(void *ptr);
void clear_matrix(void *ptr);
void set_parameters(t_program *point, t_program *mlx);

#endif
