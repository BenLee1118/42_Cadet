# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 18:19:04 by ltian-ha          #+#    #+#              #
#    Updated: 2023/03/13 21:41:15 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CHECKER			=	checker

SRCS			=    *.c
CHECKER_SRCS		=	*.c checker.c

OBJS			=    ${SRCS:.c=.o}
CHECKER_OBJS	=	${CHECKER_SRCS:.c=.o}

# ARCR			=    ar cr 
RMRF			=    rm -rf
GCC				=    gcc
CFLAGS			=    -Wall -Wextra -Werror -Iincludes


all:	${NAME} ${CHECKER}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${MAKE} -C ./ft_printf
	@${GCC} ${CFLAGS} ${SRCS} libft/libft.a ft_printf/libftprintf.a  -o ${NAME} -fsanitize=address -g3

${CHECKER}: ${CHECKER_OBJS}
	@${GCC} ${CFLAGS} ${SRCS} libft/libfi.a ft_printf/libftprintf.a -o ${CHECKER} -fsanitize=address -g3
	
clean:
	@${MAKE} -C ./libft fclean
	@${RMRF} ${OBJS} ${OBJS_DIR}
	@${RMRF} ${CHECKER_OBJS} ${OBJS_DIR}

fclean:	clean
	@${RMRF} $(NAME)
	@${RMRF} ${CHECKER}

re:	fclean all
