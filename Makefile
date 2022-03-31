NAME = fractol

OBJS = main.o pixput.o colors.o mandelbrot.o key_press.o button_press.o ft_strcmp.o init_fractals.o hsv_to_rgb.o plot_fractal.o julia.o ft_atof.o burning_ship.o close_mlx.o errors.o ft_ctype.o new_mlx.o

SUBDIRS = ft_printf mlx_linux

HEAD = img.h

MAKE = make

CC = cc

FLAGS = -Wall -Wextra -Werror

all:		$(SUBDIRS) $(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Lft_printf -lftprintf -o $(NAME)

$(SUBDIRS):
			$(MAKE) -C $@

$(OBJS): 	%.o:%.c $(HEAD)
			$(CC) $(FLAGS) -I/usr/include -Imlx_linux -c $< -o $@

clean:
			rm -rf $(OBJS)
			$(MAKE) clean -C ft_printf
			$(MAKE) clean -C mlx_linux

fclean:		clean
			rm -rf $(NAME)
			$(MAKE) fclean -C ft_printf

re:			fclean all

.PHONY: all clean fclean re $(SUBDIRS)
