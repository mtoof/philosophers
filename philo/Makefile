# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 14:04:26 by mtoof             #+#    #+#              #
#    Updated: 2023/04/24 11:57:01 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = ./header/
SRC_DIR = ./src/
vpath %.c $(SRC_DIR)
SRC = philo.c ft_atol.c check_digit.c error_handling.c init_data.c time_util.c print_msg.c \
		routine.c eaten_died.c
		
FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g -static-libsan
OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

.PHONY: obj_dir

all : $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -pthread -I$(HEADER) $^ -o $@

$(OBJ): $(OBJ_DIR)%.o: %.c | obj_dir
	gcc $(FLAGS) -pthread -I$(HEADER) -c -o $@ $<
clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

obj_dir:
	@mkdir -p $(OBJ_DIR)