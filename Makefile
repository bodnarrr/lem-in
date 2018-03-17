# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abodnar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2018/03/17 18:38:20 by abodnar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

LIB = libftprintf.a

SRCS =	main.c ft_get_ants_number.c ft_check_line_type.c ft_get_nodes.c \
		ft_add_room.c ft_clear_nodes.c ft_check_nodes.c ft_get_connects.c \
		ft_clear_lines.c ft_traverse.c ft_print_lem.c ft_join_lem.c \
		ft_check_if_road.c
		

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADERS = *.h

all: $(NAME)

%.o : %.c
	@gcc -g -I. -I./libftprintf $(FLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJECTS) $(HEADERS)
	@gcc -g -o $@ -I. -I./libftprintf $(OBJECTS) $(LIB)
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
