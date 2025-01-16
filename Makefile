# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcorcher <mcorcher@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 06:13:02 by mcorcher          #+#    #+#              #
#    Updated: 2025/01/16 06:13:03 by mcorcher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fractol

CC = cc
CFLAGS	=	-Wall -Wextra -Werror
STRUCT	= 	-Lminilibx-linux -lmlx_Linux -lX11 -lXext -o fractol
SRCS	=	render.c \
			math_utils.c \
			init.c \
			events.c \
			main.c \
			string_utils.c \

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(UTILS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) $(STRUCT) -I ./fractol.h

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re