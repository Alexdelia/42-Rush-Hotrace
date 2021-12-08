# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 15:56:29 by adelille          #+#    #+#              #
#    Updated: 2021/12/08 10:45:30 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	hotrace
CC = 	clang
RM = 	rm -rf

CFLAGS	=	-Wall -Werror -Wextra
#CFLAGS	+=	-O2
#CFLAGS	+=	-O3
#CFLAGS	+=	-Ofast
#CFLAGS	+=	-g3
#CFLAGS	+=	-fsanitize=address

#MAKEFLAGS += --silent

SRCS =		$(wildcard *.c)
OBJS =		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
