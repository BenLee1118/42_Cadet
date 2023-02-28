# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:55:06 by ltian-ha          #+#    #+#              #
#    Updated: 2023/02/28 15:56:22 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g3 -I $(INCLUDE) 
RM		= rm -rf
INCLUDE	= so_long.h

NAME	= so_long

SRCS_C	= assign.c check_valid_path.c draw_frame.c ft_itoa.c ft_putstr.c ft_split.c ft_strenlarge.c ft_strncmp.c ft_strrchr.c \
			ft_strrdup.c ft_substr.c get_next_line_utils.c get_next_line.c initialization.c inspection.c key_handlers.c \
			maplysis.c move_ghost.c movement.c render_images.c so_long.c string_put.c
SRC_O	= $(SRCS_C:.c=.o)

all:		$(NAME)

$(NAME):	$(SRC_O)
		$(CC) $(CFLAGS) $(SRC_O) -o $(NAME) -lmlx -framework OpenGL -framework Appkit

clean:
			$(RM) $(SRC_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all