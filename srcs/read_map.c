#include "../includes/fdf.h"

int get_height(char *file_name)
{
	int fd;
	int height;
	char *line;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	free(line);
	close(fd);
	return (height);
}

int get_width(char *file_name)
{
	int fd;
	int width;
	char *line;

	fd = open(file_name, O_RDONLY, 0);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

// void fill_matrix(int *z_line, char *line)
// {
// 	char **numbers;
// 	int i;

// 	numbers = ft_split(line, ' ');
// 	i = 0;
// 	while (numbers[i])
// 	{
// 		z_line[i] = ft_atoi(numbers[i]);
// 		free(numbers[i]);
// 		i++;
// 	}
// 	free(numbers);
// }

// void read_file(char *file_name, t_program *coord)
// {
// 	int fd;
// 	char *line;
// 	int i;

// 	coord->height = get_height(file_name);
// 	coord->width = get_width(file_name);
// 	coord->z_matrix = (int **)malloc(sizeof(int *) * (coord->height + 1));
// 	i = 0;
// 	while (i <= coord->height - 1)
// 		coord->z_matrix[i++] = (int *)malloc(sizeof(int) * (coord->width + 1));
// 	fd = open(file_name, O_RDONLY, 0);
// 	i = 0;
// 	while (get_next_line(fd, &line))
// 	{
// 		fill_matrix(coord->z_matrix[i], line);
// 		free(line);
// 		i++;
// 	}
// 	free(line);
// 	coord->z_matrix[i] = NULL;
// }

int fill_matrix_lines(char *line, t_program **map_matrix, int y)
{
	char **points;
	int x;

	points = ft_strsplit(line, ' ');
	x = 0;
	while (points[x])
	{
		map_matrix[y][x].z = ft_atoi(points[x]);
		map_matrix[y][x].x = x;
		map_matrix[y][x].y = y;
		map_matrix[y][x].is_last_matrix_point = 0;
		free(points[x++]);
	}
	free(points);
	free(line);
	map_matrix[y][--x].is_last_matrix_point = 1;
	return (x);
}

t_program **create_coordinates_matrix(char *file_name)
{
	t_program **new_matrix;
	int x;
	int y;
	int fd;
	char *line;

	if ((fd = open(file_name, O_RDONLY, 0)) <= 0)
		ft_puterror("Error opening file", -1);
	get_next_line(fd, &line);
	x = ft_wdcounter(line, ' ');
	free(line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		free(line);
	}
	free(line);
	new_matrix = (t_program **)malloc(sizeof(t_program *) * (++y + 1));
	if (!new_matrix)
		ft_puterror("Memory allocation error", -1);
	while (y > 0)
		new_matrix[--y] = (t_program *)malloc(sizeof(t_program) * (x + 1));
	close(fd);
	return (new_matrix);
}

t_program **read_map(char *file_name)
{
	t_program **coordinates_matrix;
	int y;
	int fd;
	char *line;

	coordinates_matrix = create_coordinates_matrix(file_name);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		ft_puterror("Error opening file", -1);
	y = 0;
	while (get_next_line(fd, &line) > 0)
		fill_matrix_lines(line, coordinates_matrix, y++);
	free(line);
	coordinates_matrix[y] = NULL;
	close(fd);
	return (coordinates_matrix);
}
