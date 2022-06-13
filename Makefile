# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gilee <gilee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 21:03:11 by gilee             #+#    #+#              #
#    Updated: 2021/06/21 21:04:20 by gilee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  		= server
NAME2 		= client
B_NAME  	= b_server
B_NAME2 	= b_client

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
INCLUDE 	= -I./libft/

LIB_DIR 	= ./libft/
LIB_NAME	= ft
LIB			= $(LIB_DIR)lib$(LIB_NAME).a

all : MAKE_LIB $(NAME) $(NAME2)

bonus : $(B_NAME) $(B_NAME2)

clean :
	make -C $(LIB_DIR) clean

fclean : clean
	rm -rf $(NAME) $(NAME2) $(LIB)

re : fclean all

MAKE_LIB :
	make -C $(LIB_DIR) all

$(NAME) : $(NAME).c
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE) -L$(LIB_DIR) -l$(LIB_NAME)

$(NAME2) : $(NAME2).c
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE) -L$(LIB_DIR) -l$(LIB_NAME)

$(B_NAME) : $(NAME)_bonus.c
	$(CC) $(CFLAGS) $< -o $(NAME) $(INCLUDE) -L$(LIB_DIR) -l$(LIB_NAME)

$(B_NAME2) : $(NAME2)_bonus.c
	$(CC) $(CFLAGS) $< -o $(NAME2) $(INCLUDE) -L$(LIB_DIR) -l$(LIB_NAME)

.PHONY : all clean fclean re
