# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 05:11:13 by ltian-ha          #+#    #+#              #
#    Updated: 2022/10/24 05:11:13 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar -rcs
LIB2	= ranlib
RM		= rm -rf
INCLUDE	= libft.h

NAME	= libft.a

SRCS_C	= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c
SRC_O	= $(SRCS_C:.c=.o)
BON_C	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstmap.c ft_lstiter.c
BON_O	= $(BON_C:.c=.o)

all:		$(NAME)

$(NAME):	$(SRC_O) $(INCLUDE)
			$(AR) $(NAME) $(SRC_O)
			$(LIB2) $(NAME)

bonus:		$(NAME) $(BON_O)
			$(AR) $(NAME) $(BON_O)
			$(LIB2) $(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(SRC_O) $(BON_O)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all