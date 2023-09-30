# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 12:34:39 by nnuno-ca          #+#    #+#              #
#    Updated: 2023/09/30 19:18:37 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g3
INC = -I./includes
VPATH = srcs srcs/input srcs/philos srcs/utils
RM = rm -rf

INPUT = valid_args init_args
PHILOS = init_philos routine
UTILS = ft_atoi panic destroy get_time init_forks
GENERAL = launch_threads_and_join monitoring

NAME = philo
SRCS = $(addsuffix .c, $(INPUT))\
	   $(addsuffix .c, $(PHILOS))\
	   $(addsuffix .c, $(UTILS))\
	   $(addsuffix .c, $(GENERAL))\
	   main.c

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re

.SILENT:
