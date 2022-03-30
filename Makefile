MAKE = make

all:
	+$(MAKE) -C ft_printf
	+$(MAKE) -C mlx_linux
	+$(MAKE) -C srcs

clean:
	+$(MAKE) clean -C ft_printf
	+$(MAKE) clean -C mlx_linux
	+$(MAKE) clean -C srcs

fclean:
	+$(MAKE) fclean -C ft_printf
	+$(MAKE) clean -C mlx_linux
	+$(MAKE) fclean -C srcs
	rm -rf fractol

re:	fclean all
