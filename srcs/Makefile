NAME = fractol

OBJS = main.o pixput.o colors.o mandelbrot.o key_press.o button_press.o ft_strcmp.o init_fractals.o hsv_to_rgb.o plot_fractal.o julia.o ft_atof.o burning_ship.o close_win.o errors.o ft_ctype.o

HEAD = img.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) -L../mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L../ft_printf -lftprintf -o $(NAME)

$(OBJS): 	%.o:%.c $(HEAD)
			$(CC) $(FLAGS) -I/usr/include -I../mlx_linux -O3 -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)
