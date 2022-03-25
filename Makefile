NAME = fractol

OBJS = main.o my_pixel_put.o colors.o mandelbrot.o key_press.o button_press.o ft_strcmp.o init_fractals.o hsv_to_rgb.o plot_fractal.o julia.o ft_atof.o burning_ship.o close.o errors.o ft_ctype.o

HEAD = img.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): 	%.o:%.c $(HEAD)
			$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)
