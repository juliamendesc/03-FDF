#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

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

void fill_matrix(int *z_line, char *line)
{
	char **numbers;
	int i;

	numbers = ft_strsplit(line, ' ');
	i = 0;
	while (numbers[i])
	{
		z_line[i] = ft_atoi(numbers[i]);
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

void read_file(char *file_name, t_coordinates *coord)
{

	int fd;
	char *line;
	int i;

	coord->height = get_height(file_name);
	coord->width = get_width(file_name);
	coord->z_matrix = (int **)malloc(sizeof(int *) * (coord->height + 1));
	i = 0;
	while (i <= coord->height)
		coord->z_matrix[i++] = (int *)malloc(sizeof(int) * (coord->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(coord->z_matrix[i], line);
		free(line);
		i++;
	}
	coord->z_matrix[i] = NULL;
}
