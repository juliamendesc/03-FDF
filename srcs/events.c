#include "../includes/fdf.h"

int key_pressed(int keycode, void *param)
{
	printf("key code: %d\t- param: %p\n", keycode, param);
	return (0);
}

int mouse_clicked(int button, int x, int y)
{
	printf("button code: %d\t- coordinate (x: %d, y: %d)\n", button, x, y);
	return (0);
}

int key_up(int key)
{
	key == 53 ? exit(0) : 0;
	return (0);
}
