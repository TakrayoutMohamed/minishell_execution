# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 22:02:20 by mohtakra          #+#    #+#              #
#    Updated: 2023/07/31 15:20:16 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MINISHELL
LIBMINI=libmini.a
CC=cc
CFLAGS=
# CFLAGS=-Wall -Werror -Wextra
RM=rm -f

READLINE_INC = -I $(shell brew --prefix readline)/include 
READLINE_LIB = -lreadline -L $(shell brew --prefix readline)/lib

PATHEXEC= ./execution/
PATHPARS= ./parsing/

SRC= $(PATHEXEC)prompt.c \
	 $(PATHPARS)parse_data.c
MAIN_SRC=minishell.c

OBJ=$(SRC:.c=.o)
MAIN_OBJ=$(MAIN_SRC:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) $(MAIN_OBJ) $(LIBMINI)
		$(CC) $(READLINE_LIB) -o $@  $(LIBMINI) $(MAIN_OBJ)
		@echo "the executable $@ has been created"

$(LIBMINI): $(OBJ)
		ar rc  $@ $(OBJ)
		@echo "the libmini.a archieve has been created"

%.o: %.c ./libminishell.h ./libtree.h
		$(CC) $(READLINE_INC) $(CFLAGS) -o $@ -c $<
		@echo "object $@ has been created from $<"

clean:
	$(RM) $(OBJ) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBMINI)
	
re: fclean all

.PHONY: clean fclean re $(NAME) $(LIBMINI) all
