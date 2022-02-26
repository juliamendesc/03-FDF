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
typedef struct s_coordinates
{
	int width;
	int height;
	int **z_matrix;
	int zoom;
} t_coordinates;

typedef struct s_point
{
	float x;
	float y;
	int z;
	int color;
} t_point;

typedef struct s_program
{
	void *mlx_pointer;
	void *mlx_win;
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_program;

typedef struct s_basis
{
	int scale;
	int z_scale;
	int shift_x;
	int shift_y;
	int is_isometric;
	double angle;
	int win_x;
	int win_y;
	void *mlx_ptr;
	void *win_ptr;
} t_basis;

void read_file(char *file_name, t_coordinates *coord);
void fill_matrix(int *z_line, char *line);
int get_width(char *file_name);
int get_height(char *file_name);
void my_mlx_pixel_put(t_program *data, int x, int y, int color);
void draw_line(t_point m0, t_point m1, t_coordinates *coord, t_program *img);
int key_pressed(int keycode, t_program *mlx);
int mouse_clicked(int button, int x, int y, t_program *mlx);
void draw_map(t_coordinates *coord, t_program *img);
void isometric_projection(t_point *m, t_program *mlx);
t_program *init_program(void);
t_coordinates *init_coordinates(void);
t_point apply_zoom(t_point m, t_coordinates *coord);

#endif
