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
LIBFT		=	cd libft && make
LIB			=	./libft/libft.a
RM			=	rm -rf

$(NAME) :
	$(LIBFT)
	$(CC) $(CFLAGS) $(SOURCES) $(LIB) -o $(NAME)

all : $(NAME)

fclean : clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

clean :
	@$(MAKE) clean -C ./libft
	@$(RM) $(NAME)

re : fclean all