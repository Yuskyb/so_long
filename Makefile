# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yususato <yususato@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 20:28:35 by yususato          #+#    #+#              #
#    Updated: 2023/10/23 17:10:16 by yususato         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
INCLUDES_DIR = ./Includes
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR) -g 
# -fsanitize=address

SRCS = so_long.c

OBJS = $(SRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
# $(NAME): $(OBJ)
# 	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re