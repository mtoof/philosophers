# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 14:04:26 by mtoof             #+#    #+#              #
#    Updated: 2023/07/04 16:40:12 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

HEADER = ./header/
SRC_DIR = ./src/
vpath %.c $(SRC_DIR)
SRC = philo.c ft_atoi.c check_digit.c error_handling.c init_data.c time_util.c print_msg.c \
		routine.c observer.c ft_free.c

FLAGS = -Wall -Wextra -Werror -o2 #-fsanitize=thread
OBJ_DIR = obj/
OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

.PHONY: all clean fclean re

all : $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32mCompiling files.\c\033[0m"
	@sleep 0.1
	@echo "\033[0;32m.\c\033[0m"
	@sleep 0.1
	@echo "\033[0;32m.\033[0m"
	@gcc $(FLAGS) -pthread -I$(HEADER) $^ -o $@
	@echo "\033[0;32mDone.\033[0m"

$(OBJ): $(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@gcc $(FLAGS) -pthread -I$(HEADER) -c -o $@ $<
clean:
	@echo "\033[0;35mOBJ files have been deleted.\033[0m"
	@rm -rf $(OBJ_DIR)
fclean: clean
	@echo "\033[0;31mPhilo exec file has been deleted.\033[0m"
	@rm -f $(NAME)
re: fclean all

$(OBJ_DIR):
	@echo "\033[0mCreate OBJ Dir"
	@mkdir -p $(OBJ_DIR)
