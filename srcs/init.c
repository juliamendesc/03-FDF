#include "../includes/fdf.h"

void init_program(t_program **data, char *file_name)
{
	(*data)->mlx_pointer = mlx_init();
	(*data)->mlx_win = mlx_new_window((*data)->mlx_pointer, WIDTH, HEIGHT, "FDF");
	(*data)->img = mlx_new_image((*data)->mlx_pointer, WIDTH, HEIGHT);
	(*data)->addr = mlx_get_data_addr((*data)->img, &(*data)->bits_per_pixel, &(*data)->line_length, &(*data)->endian);
	(*data)->z_matrix = NULL;
	(*data)->adapt_x = WIDTH / 3;
	(*data)->adapt_y = HEIGHT / 3;
	(*data)->angle = 0.54;

	(*data)->width = get_width(file_name);
	(*data)->height = get_height(file_name);
	(*data)->diagonal = ft_abs(sqrt(pow((*data)->height, 2) + pow((*data)->width, 2)));

	(*data)->scale_height = (float)(*data)->height / (*data)->diagonal;
	(*data)->scale_width = (float)(*data)->width / (*data)->diagonal;
	(*data)->scale = ft_min((float)(*data)->scale_width, (float)(*data)->scale_height);
	printf("mlx height before = %d\n", (*data)->height);
	printf("mlx width before= %d\n", (*data)->width);
	printf("scale before %f\n", (*data)->scale);
	printf("scale height before %f\n", (*data)->scale_height);
	printf("scale width before %f\n", (*data)->scale_width);
	printf("diagonal before %d\n", (*data)->diagonal);
}

void apply_zoom(t_program *m0, t_program *m1, t_program *coord)
{
	m0->x = m0->x * coord->scale;
	m0->y = m0->y * coord->scale;
	m0->z = m0->z * coord->scale;
	m1->x = m1->x * coord->scale;
	m1->y = m1->y * coord->scale;
	m1->z = m1->z * coord->scale;
}

int apply_color(t_program m0, t_program m1)
{
	if (m0.z || m1.z)
		return (0xfc0345);
	if (m0.z != m1.z)
		return (0xfc031c);
	else
		return (0xBBFAFF);
}
