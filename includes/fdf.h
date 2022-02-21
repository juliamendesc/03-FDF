#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

#define MAX(a, b) (a > b ? a : b)

typedef struct s_coordinates
{
	int width;
	int height;
	int **z_matrix;
	int zoom;
	int color;
} t_coordinates;

typedef struct s_data
{

} t_data;

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

void read_file(char *file_name, t_coordinates *coord);
void fill_matrix(int *z_line, char *line);
int get_width(char *file_name);
int get_height(char *file_name);
void my_mlx_pixel_put(t_program *data, int x, int y, int color);
void draw_line(float x, float y, float x1, float y1, t_coordinates *coord, t_program *img);
int press_key(int key, void *data);
void draw_map(t_coordinates *coord, t_program *img);
void isometric_projection(float *x, float *y, int z);
