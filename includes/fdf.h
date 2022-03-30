#ifndef FDF_H

#define FDF_H

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

#define MAX(a, b) (a > b ? a : b)
#define WIDTH 1280
#define HEIGHT 720
#define BUTTON_PRESS_MASK (1L << 2)
#define BUTTON_RELEASE_MASK (1L << 3)
#define KEY_ESCAPE 65307
#define MOUSE_LEFT_BUTTON 1
typedef struct s_program
{
	/* POINT */
	float x;
	float y;
	float z;
	// int color;
	int is_last_matrix_point;

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

	/* COORDINATES */
	int width;
	int height;
	int **z_matrix;
} t_program;

/* INIT STRUCTS */
void init_program(t_program **data, char *file_name);
void apply_zoom(t_program *m0, t_program *m1, t_program *coord);
int apply_color(t_program m0, t_program m1);

/* FETCHING COORDINATES */
int get_height(char *file_name);
int get_width(char *file_name);
void fill_matrix(int *z_line, char *line);
void read_file(char *file_name, t_program *coord);

/* HOOKS */
int key_pressed(int keycode);
int mouse_clicked(int button, int x, int y, t_program *mlx);

/* DRAWING */
void my_mlx_pixel_put(t_program *data, int x, int y, int color);
void draw_line(t_program m0, t_program m1, t_program *mlx);
void draw_map(t_program **coordinates_matrix, t_program *mlx);
void clear_mlx_data(void *ptr);
void clear_matrix(void *ptr);
void set_parameters(t_program *a, t_program *b, t_program *mlx);

t_program **read_map(char *file_name);
int fill_matrix_lines(char *line, t_program **matrix_of_dots, int y);

#endif
