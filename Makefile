# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abodnar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2018/03/01 12:55:22 by abodnar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = libftprintf.a

SRCS =	main.c ft_get_ants_number.c ft_check_line_type.c ft_get_nodes.c \
		ft_add_room.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	@gcc -I. -I./libftprintf $(FLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJECTS)
	@gcc -o $@ -I. -I./libftprintf $(OBJECTS) $(LIB)
	@echo "\033[1;32mLem-in is ready\033[0m"

$(LIB):
	@make -C ./libftprintf/
	@cp ./libftprintf/libftprintf.a .

clean:
	@make fclean -C ./libftprintf
	@rm -f *.o
	@rm -f libftprintf.a
	@echo "\033[1;32mObject files Lem-in were removed\033[0m"

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
