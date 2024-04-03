# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulefevr <hulefevr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 12:51:24 by hulefevr          #+#    #+#              #
#    Updated: 2024/04/03 18:38:11 by hulefevr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

BIN = bsq

#SRC = $(wildcard *.c)

SRC = 	./src/bsq.c \
		./src/game_check_full.c \
		./src/algo.c \
		./src/map/get_map.c \
		./src/map/print_map.c \
		./src/errors/check_errors.c \
		./src/errors/ft_strerror.c \
		./src/libft/ft_split.c \
		./src/libft/ft_strdup.c \
		./src/libft/ft_strlen.c \
		./src/libft/ft_putstr_fd.c \
		./src/libft/ft_putchar_fd.c \
		./src/libft/ft_atoi.c \

OBJ	= ${SRC:.c=.o}

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(wildcard *.o)

fclean: clean
	rm -f $(BIN)
	rm -f *.out

re: fclean all

.PHONY: all clean fclean re