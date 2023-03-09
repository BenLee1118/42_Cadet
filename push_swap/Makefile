# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 18:19:04 by ltian-ha          #+#    #+#              #
#    Updated: 2023/03/09 18:22:44 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       	=    push_swap
SRCS        =    *.c
OBJS         =    $(SRCS:.c=.o)
ARCR        =     ar cr 
RMRF        =    rm -rf
CFLAGS        =    -Wall -Wextra -Werror
GCC            =    gcc


all:	$(NAME)

$(NAME):
	${GCC} ${CFLAGS} ${SRCS} libft/libft.a ft_printf/libftprintf.a  -o $(NAME) -fsanitize=address -g3

clean:
	${RMRF} ${OBJS} ${OBJS_DIR}

fclean:	clean
	${RMRF}	$(NAME)

re:	fclean all
