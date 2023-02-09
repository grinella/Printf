NAME = libftprintf.a

SRC = ft_printf.c \
		ft_printf1.c \
		ft_printf2.c \


FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
