NAME := libftprintf.a

OBJS := ft_printf.o ft_putchar.o ft_putstr.o ft_putptr.o \
	ft_putnbr.o ft_u_putnbr.o ft_puthex.o redirect.o

CC := gcc

FLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c ft_printf.h
	$(CC) -c $(FLAGS) $< -o $@

.PHONY = all clean fclean re

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
