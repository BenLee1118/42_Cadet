# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 15:36:28 by ltian-ha          #+#    #+#              #
#    Updated: 2023/10/02 15:36:28 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=thread -g3
SOURCES		=	checkers.c initialize.c philo.c utilities.c
RM			=	rm -rf

$(NAME) :
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all