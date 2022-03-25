#include "img.h"

inline void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + x * (data->bits / 8) + y * data->len;
	*(unsigned int*)dst = color;
}
