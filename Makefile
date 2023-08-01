# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 22:02:20 by mohtakra          #+#    #+#              #
#    Updated: 2023/08/01 12:57:56 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MINISHELL
LIBMINI=libmini.a
CC=cc
CFLAGS=
# CFLAGS=-Wall -Werror -Wextra
RM=rm -f

# READLINE_INC = -I/goinfre/$(USER)/homebrew/opt/readline/include		 //linux
# READLINE_LIB = -lreadline -L/goinfre/$(USER)/homebrew/opt/readline/lib //linux

READLINE_INC = -I $(shell brew --prefix readline)/include 				#MAC
READLINE_LIB = -lreadline -L $(shell brew --prefix readline)/lib		#MAC

PATHEXEC= ./execution/
PATHPARS= ./parsing/

SRC= $(PATHEXEC)prompt.c \
	 $(PATHPARS)parse_data.c
MAIN_SRC=minishell.c

OBJ=$(SRC:.c=.o)
MAIN_OBJ=$(MAIN_SRC:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) $(MAIN_OBJ) $(LIBMINI)
		$(CC) -o $@  $(LIBMINI) $(MAIN_OBJ) $(OBJ) $(READLINE_LIB)
		@echo "the executable $@ has been created"

$(LIBMINI): $(OBJ)
		ar rc  $@ $(OBJ)
		@echo "the libmini.a archieve has been created"

%.o: %.c ./libminishell.h ./libtree.h
		$(CC) $(CFLAGS) -o $@ -c $< $(READLINE_INC)
		@echo "object $@ has been created from $<"

clean:
	$(RM) $(OBJ) $(MAIN_OBJ)

fclean: clean
	$(RM) $(NAME) $(LIBMINI)
	
re: fclean all

.PHONY: clean fclean re $(NAME) $(LIBMINI) all
