# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 22:23:12 by ltian-ha          #+#    #+#              #
#    Updated: 2023/08/29 23:22:18 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ----------------------------------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE		=	-I include
LIBFT		=	cd libft && make
LIB = ./libft/libft.a
RM = rm -rf

SERVER = server
CLIENT = client

SV_SRCS = srcs/server.c
SV_OBJS = $(SV_SRCS:.c=.o)

CLIENT_SRCS = srcs/client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)



SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SV_BONUS_SRCS = srcs_bonus/server_bonus.c
SV_BONUS_OBJS = $(SV_BONUS_SRCS:.c=.o)

CLIENT_BONUS_SRCS = srcs_bonus/client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

all: comp_start ft_server $(CLIENT)

# $(LIBFT):
# 	$(MAKE) -C ./libft

comp_start:
	@$(COMP_START)
	@$(LIBFT)

# $(SERVER): $(SV_OBJS)
# 	@$(CC) $(CFLAGS) $(SV_OBJS) $(LIB) -o server
# 	@$(SERV_READY)
ft_server: $(SV_OBJS)
	@$(CC) $(CFLAGS) $(SV_OBJS) $(LIB) -o $(SERVER)
	@$(SERV_READY)

$(CLIENT): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o client
	@$(CLI_READY)
	
# $(SERVER_BONUS): $(SV_BONUS_OBJS) $(LIBFT)
# 	@$(CC) $(CFLAGS) $(SV_BONUS_OBJS) $(LIBFT) -o server_bonus
	
# $(CLIENT_BONUS): $(CLIENT_BONUS_OBJS) $(LIBFT)
# 	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIBFT) -o client_bonus

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(SV_OBJS) $(CLIENT_OBJS)
	@$(RM) $(SV_BONUS_OBJS) $(CLIENT_BONUS_OBJS)
	@$(CLEANED)
	
fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
	@$(FCLEANED)

.c.o:
	@${CC} ${CFLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)