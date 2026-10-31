CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rcs

HEADER = ft_printf.h

NAME = libftprintf.a

SRC = ft_printf.c \
		printf_char.c \
		printf_decimal.c \
		printf_hexa.c \
		printf_pointer.c \
		printf_str.c \
		printf_unsigned_integer.c
OBJ = $(SRC:.c=.o)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean