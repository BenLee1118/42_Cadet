# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 18:19:04 by ltian-ha          #+#    #+#              #
#    Updated: 2023/08/02 21:55:26 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= 
SRC			= ft_add_sort ft_atoilong ft_check_params ft_index_arrange ft_operations ft_sec_operations \
				ft_sort_algo ft_sort_radix ft_strcmp ft_t_prop ft_thir_operations ft_utilitize get_next_line_utils get_next_line \
				push_swap
BONUS_SRC1	= ft_add_sort ft_atoilong ft_check_params ft_index_arrange ft_operations ft_sec_operations \
				ft_sort_algo ft_sort_radix ft_strcmp ft_t_prop ft_thir_operations ft_utilitize get_next_line_utils get_next_line
BONUS_SRC2	= checker
SRCS_N_MAIN	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(BONUS_SRC1)))
SRCS		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC)))
LIBFT_DIR	= Libft
LIBFT		= libft.a
NAME		= push_swap.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RED			:= $(shell tput -Txterm setaf 1)
RESET		:= $(shell tput -Txterm sgr0)
BONUS_DIR	= 
BONUS_SRC	= checker
BONUS_SRCS	= $(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_SRC2)))

all:
	mkdir -p $(OBJS_DIR)
	make do

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

do: $(NAME)

$(NAME) : $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	touch $(NAME)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar -crs $(NAME) $(OBJS)
	make run
	clear
	@echo "$(RED)fsanitize sort created"

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

del:
	rm $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(BONUS_SRCS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	cd $(LIBFT_DIR) && $(MAKE) fclean
	clear
	@echo "removed .o .a files"
	rm -rf push_swap checker

run:
	@$(CC) $(CFLAGS) $(SRCS) $(NAME) -o push_swap

bonus: all
	@$(CC) $(CFLAGS) $(BONUS_SRCS) $(SRCS_N_MAIN) $(LIBFT_DIR)/$(LIBFT) -o checker
	clear
	@echo "cheker file created"

tester:
	cd push_swap_tester && bash basic_test.sh