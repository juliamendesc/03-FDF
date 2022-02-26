// #include "../includes/fdf.h"

// void check_coordinate(char *temp)
// {
// 	int i;
// 	char **z_info;

// 	z_info = ft_split(temp, '');
// }

// void check_map(char *filename, t_coordinates *coords)
// {

// 	int i;
// 	int j;
// 	int fd;
// 	char *line;
// 	char **temp;

// 	fd = open(filename, O_RDONLY, 0);
// 	if (fd < 0)
// 		ft_puterror("Error: file not found\n", -1);
// 	while (get_next_line(fd, &line))
// 	{
// 		i = -1;
// 		temp = ft_split(line, ' ');
// 		while (temp[++i])
// 			if (check_coordinate(temp[i] < 0))
// 				ft_puterror("Error: wrong coordinate\n", -1);
// 		free(temp);
// 		free(line);
// 		if (coords->width != -1 && i != coords->width)
// 			ft_puterror("Error: wrong number of coordinates\n", -1);
// 		coords->width = i;
// 		coords->height++;
// 	}
// 	close(fd);
// }
