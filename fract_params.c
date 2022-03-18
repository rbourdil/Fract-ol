#include "img.h"

#define RED 315
#define GREEN 529
#define BLUE 424
#define BLACK 509
#define WHITE 545

static int	string_to_color(char *s)
{
	int	color;

	color = 0;
	while (*s != '\0')
		color += *s++;	
	if (color == RED)
		return (0x00FF0000);
	else if (color == GREEN) 
		return (0x0000FF00);
	else if (color == BLUE)
		return (0x000000FF);
	else if (color == BLACK)
		return (0);
	else if (color == WHITE)
		return (0x00FFFFFF);
	else
		return (-1);
}
	
void	fract_params(t_vars *vars, int choice, char *color1, char *color2)
{
	if (choice == MANDELBROT)
	{
		vars->loc.xb = -2.0;
		vars->loc.xe = 0.47;
		vars->loc.yb = -1.12;
		vars->loc.ye = 1.12;
	}
	vars->fract->color1 = string_to_color(color1);
	vars->fract->color2 = string_to_color(color2);
}
