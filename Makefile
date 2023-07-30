# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 22:02:20 by mohtakra          #+#    #+#              #
#    Updated: 2023/07/30 17:31:47 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MINISHELL
LIBMINI=libmini.a
CC=cc
CFLAGS=
# CFLAGS=-Wall -Werror -Wextra
RM=rm -f

SRC= test.c
MAIN_SRC=minishell.c
OBJ=$(SRC:.c=.o)
MAIN_OBJ=$(MAIN_SRC:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) $(MAIN_OBJ) $(LIBMINI)
		$(CC) -o $@ $(MAIN_OBJ) $(LIBMINI)
		@echo "the executable $@ has been created"

$(LIBMINI): $(OBJ)
		ar rc $@ $(OBJ)
		@echo "the libmini.a archieve has been created"

%.o: %.c ./libminishell.h
		$(CC) $(CFLAGS) -o $@ -c $<
		@echo "object $@ has been created from $<"

clean:
	$(RM) $(OBJ) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBMINI)
	
re: fclean all

.PHONY: clean fclean re $(NAME) $(LIBMINI) all
