# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/04 14:38:49 by meskelin          #+#    #+#              #
#    Updated: 2023/09/30 19:20:20 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

BUILD_FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g3

COMMON_SRC =	validate \
				nbr \
				ft_print \
				sleep \
				time \
				memory

INIT_SRC =	init \
			init_forks \
 			init_philos \
			clean

SIM_SRC =	forks \
			philosophers \
			routine \
			simulation \
			threads \
			checks

H_FILES = philo

COMMONSRCPRE = $(addprefix ./common/, $(COMMON_SRC))
COMMONSRCSUFF = $(addsuffix .c, $(COMMONSRCPRE))
INITSRCPRE = $(addprefix ./data/, $(INIT_SRC))
INITSRCSUFF = $(addsuffix .c, $(INITSRCPRE))
SIMSRCPRE = $(addprefix ./simulation/, $(SIM_SRC))
SIMSRCSUFF = $(addsuffix .c, $(SIMSRCPRE))
H_PRE = $(addprefix ./headers/, $(H_FILES))
HSUFF = $(addsuffix .h, $(H_PRE))

.PHONY = all
all: $(NAME)

$(NAME):
	cc $(BUILD_FLAGS) $(COMMONSRCSUFF) $(SIMSRCSUFF) $(INITSRCSUFF) main.c -o $(NAME)

.PHONY: clean
clean:
	rm -f $(SRCSO)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

