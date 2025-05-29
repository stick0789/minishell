# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaacosta <jaacosta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:47:40 by jaacosta          #+#    #+#              #
#    Updated: 2025/05/29 18:02:39 by jaacosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
LDFLAGS = -lreadline -lncurses
AR	= ar -rcs
RM	= rm -rf

SRCS 	=  futuros_archivos.c
	  
SRC_PATH = ./src/
OBJ_PATH = ./tmp/
H_PATH	 = ./includes

HEADERS  = -I$(H_PATH)

#DIRSRC	 = $(addprefix $(SRC_PATH), $(SRCS))
#OBJS 	 = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))
DIRSRC	 = $(shell find $(SRC_PATH) -name "*.c")
OBJS 	 = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRCS))

all	:	makelib $(OBJ_PATH) $(NAME)

makelib	:	
		$(MAKE) -C libft 

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)
		echo "Directorio $(OBJ_PATH) creado."

$(NAME)	:	$(OBJS) 
		$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) libft/libft.a -o $(NAME)
		

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c Makefile libft/libft.a 
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@


clean	:
		$(RM) $(OBJ_PATH)
		$(MAKE) -C libft clean

fclean	:
		$(RM) $(NAME) $(OBJ_PATH)
		$(MAKE) -C libft fclean

re	:
		$(MAKE) fclean 
		$(MAKE) all 
		
.PHONY	:	makelib all clean fclean re
