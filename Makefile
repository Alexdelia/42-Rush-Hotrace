# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 15:56:29 by adelille          #+#    #+#              #
#    Updated: 2021/12/11 21:37:57 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	hotrace
CC = 	cc
RM = 	rm -rf

CFLAGS	=	-Wall -Werror -Wextra
#CFLAGS	+=	-O2
CFLAGS	+=	-O3
#CFLAGS	+=	-Ofast
CFLAGS	+=	-g3
#CFLAGS	+=	-pg
#CFLAGS	+=	-fsanitize=address

#CFLAGS	+=	-DBUFFER_SIZE=1000000000

#MAKEFLAGS += --silent

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

SRCS =		$(wildcard $(SRCSPATH)*.c) $(wildcard $(SRCSPATH)**/*.c)
SRCSNAME =	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME =	$(SRCSNAME:.c=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJSPATH)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
