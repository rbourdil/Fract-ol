#include "img.h"
#define ABS(x) ((x < 0) ? x * -1 : x)

int	main(void)
{
	t_vars	vars;
	double	mod, a, b;
	unsigned int		m;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGTH, "Moving Square");
	vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGTH);
	vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits, &vars.data.len, &vars.data.endian);
	m = 0;
	while (m % 0x00ffffff < 0xffffffff)
	{
		vars.data.img = mlx_new_image(vars.mlx, WIDTH, HEIGTH);
		vars.data.addr = mlx_get_data_addr(vars.data.img, &vars.data.bits, &vars.data.len, &vars.data.endian);
		for (int i = 0; i < WIDTH; i++)
			for (int j = 0; j < HEIGTH; j++)
			{
				a = (double)i - WIDTH / 2.0;
				b = HEIGTH / 2.0 - (double)j;
				mod = sqrt(a * a + b * b);
				if (mod < HEIGTH / 2.0)
					my_pixel_put(&vars.data, i, j, i * m * m);
			}
		mlx_put_image_to_window(vars.mlx, vars.win, vars.data.img, 0, 0);
		mlx_destroy_image(vars.mlx, vars.data.img);
		m++;
	}
	return (0);
}
