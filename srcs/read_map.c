#include "../includes/fdf.h"

int get_height(char *file_name)
{
	int fd;
	int height;
	char *line;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
		ft_puterror("Error: open failed\n", -1);
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
	if (fd == -1)
		ft_puterror("Error: open failed\n", -1);
	get_next_line(fd, &line);
	width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

int fill_matrix_lines(char *line, t_program **map_matrix, int y)
{
	char **points;
	int x;

	if (ft_strchr(line, ','))
	{
		points = ft_strsplit(line, ',');
		x = 0;
		while (points[x])
		{
			printf("in the loop\n");
			map_matrix[y][x].z = ft_atoi(points[x]);
			map_matrix[y][x].x = x;
			map_matrix[y][x].y = y;
			map_matrix[y][x].color = (ft_atoi_base(points[x], HEXADECIMAL_BASE));
			printf("color = %d\n", map_matrix[y][x].color);
			map_matrix[y][x].is_last_matrix_point = 0;
			free(points[x++]);
		}
		free(points);
		free(line);
		map_matrix[y][--x].is_last_matrix_point = 1;
		return (x);
	}
	else
	{
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
}

t_program **create_coordinates_matrix(char *file_name)
{
	t_program **new_matrix;
	int x;
	int y;

	x = get_width(file_name);
	y = get_height(file_name);
	new_matrix = (t_program **)malloc(sizeof(t_program *) * (y + 1));
	check_malloc(new_matrix);
	while (y > 0)
		new_matrix[--y] = (t_program *)malloc(sizeof(t_program) * (x + 1));
	check_malloc(new_matrix);
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
