# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@stdudent.hive.fi>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 20:07:03 by mtoof             #+#    #+#              #
#    Updated: 2023/04/10 20:24:59 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo
SRC_DIR = src/
vpath %.c $(SRC_DIR)
SRC = philo.c
HEADER = header/
OBJ_DIR = obj/
OBJ= $(SRC:%.c=$(OBJ_DIR)%.o)
FLAGS = -Wall -Wextra -Werror

.PHONEY = obj_dir

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?

$(OBJ): $(OBJ_DIR)%.o: %.c | obj_dir
	gcc $(FLAGS) -I$(HEADER) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all
obj_dir:
	mkdir -p $(OBJ_DIR)