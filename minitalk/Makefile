# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltian-ha <ltian-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 22:23:12 by ltian-ha          #+#    #+#              #
#    Updated: 2023/08/30 20:24:34 by ltian-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# __________________________________Colors__________________________________

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# __________________________________Messages________________________________

COMP_START			=	echo "\n🚥 🚴 🏃 $(BOLD_YELLOW)MakeFile: $(NO_COLOR)Compilation Running...\n"
SERV_READY			=	echo "\n🎉 Mandatory Server Ready!\n"
SERV_BONUS_READY 	=	echo "\n🎊 Server Bonus Ready!\n"
CLI_READY			=	echo "\n🈯 Mandatory Client Ready!\n"
CLI_BONUS_READY 	=	echo "\n🎬 Client Bonus Ready!\n"
CLEANED				=	echo "\n🚿 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED			=	echo "\n🛁 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# __________________________________Commands Initialization________________________________

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror
INCLUDE		= -I include
LIBFT		= cd libft && make
LIB			= ./libft/libft.a
RM 			= rm -rf

# __________________________________File Names________________________________

# Sources
SERVER = server
CLIENT = client

SV_SRCS = srcs/server.c
SV_OBJS = $(SV_SRCS:.c=.o)

CLIENT_SRCS = srcs/client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

# Sources Bonus
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SV_BONUS_SRCS = srcs_bonus/server_bonus.c
SV_BONUS_OBJS = $(SV_BONUS_SRCS:.c=.o)

CLIENT_BONUS_SRCS = srcs_bonus/client_bonus.c
CLIENT_BONUS_OBJS = $(CLIENT_BONUS_SRCS:.c=.o)

# __________________________________Rules Make________________________________

all: comp_start src_server src_client

comp_start:
	@$(COMP_START)
	@$(LIBFT)

src_server: $(SV_OBJS)
	@$(CC) $(CFLAGS) $(SV_OBJS) $(LIB) -o $(SERVER)
	@$(SERV_READY)

src_client: $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o $(CLIENT)
	@$(CLI_READY)
	
srcs_server_bonus: $(SV_BONUS_OBJS)
	@$(CC) $(CFLAGS) $(SV_BONUS_OBJS) $(LIB) -o server_bonus
	@$(SERV_BONUS_READY)

srcs_client_bonus: $(CLIENT_BONUS_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJS) $(LIB) -o client_bonus
	@$(CLI_BONUS_READY)

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

bonus: srcs_server_bonus srcs_client_bonus