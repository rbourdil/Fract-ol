MAKE := make

CLEAN := make clean

FCLEAN := make fclean

SUBDIRS := srcs mlx_linux ft_printf

all: 		$(SUBDIRS)

$(SUBDIRS):
			$(MAKE) -C $@

srcs: 		ft_printf mlx_linux

clean:
			+$(MAKE) clean -C ft_printf
			+$(MAKE) clean -C mlx_linux
			+$(MAKE) clean -C srcs

fclean:
			+$(MAKE) fclean -C ft_printf
			+$(MAKE) clean -C mlx_linux
			+$(MAKE) fclean -C srcs

re:			fclean all

.PHONY: clean fclean re $(SUBDIRS)
