# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaacosta <jaacosta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:47:40 by jaacosta          #+#    #+#              #
#    Updated: 2025/05/24 19:17:57 by jaacosta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC	= cc
CFLAGS	= -Wall -Wextra -Werror #-g
LDFLAGS = -lreadline -lncurses
AR	= ar -rcs
RM	= rm -rf

SRCS 	=  futuros_archivos.c
	  
SRC_PATH = ./src/
OBJ_PATH = ./tmp/
H_PATH	 = ./includes

HEADERS  = -I$(H_PATH)

DIRSRC	 = $(addprefix $(SRC_PATH), $(SRCS))
OBJS 	 = $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

all	:	makelib makeminilib $(OBJ_PATH) $(NAME)

makelib	:	
		$(MAKE) -C libft 
		
makeminilib :	
		$(MAKE) -C minilibx-linux

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
		$(MAKE) -C minilibx-linux clean

fclean	:
		$(RM) $(NAME) $(OBJ_PATH)
		$(MAKE) -C libft fclean
		$(MAKE) -C minilibx-linux clean

re	:
		make fclean 
		make all 
		
.PHONY	:	makelib makeminilib all clean fclean re
