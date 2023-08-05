# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 22:02:20 by mohtakra          #+#    #+#              #
#    Updated: 2023/08/05 20:21:46 by mohtakra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MINISHELL
LIBMINI=libmini.a
LIBFT=./libft/libft.a
CC=cc
CFLAGS=
# CFLAGS=-Wall -Werror -Wextra
RM=rm -f

# READLINE_INC = -I/goinfre/$(USER)/homebrew/opt/readline/include		 //linux
# READLINE_LIB = -lreadline -L/goinfre/$(USER)/homebrew/opt/readline/lib //linux

READLINE_INC = -I $(shell brew --prefix readline)/include 				#MAC
READLINE_LIB = -lreadline -L $(shell brew --prefix readline)/lib		#MAC

PATHEXEC= ./execution/
PATHBUILT=$(PATHEXEC)/builtins/
PATHERR=./error_handler/
PATHPARS= ./parsing/
PATHTREE= ./tree/

SRC= $(PATHEXEC)prompt.c $(PATHEXEC)execution.c $(PATHEXEC)execute_tree.c $(PATHEXEC)convert_env_to_list.c\
	 $(PATHBUILT)is_builtins.c $(PATHBUILT)builtins.c $(PATHBUILT)cd.c $(PATHBUILT)echo.c\
	 $(PATHTREE)new_node.c $(PATHTREE)add_left.c $(PATHTREE)add_right.c  $(PATHTREE)print_tree.c \
	 $(PATHERR)print_error.c \
	 $(PATHPARS)parse_data.c 
MAIN_SRC=minishell.c



OBJ=$(SRC:.c=.o)
MAIN_OBJ=$(MAIN_SRC:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) $(MAIN_OBJ) $(LIBMINI)
		$(CC) -o $@  $(LIBMINI) $(LIBFT) $(MAIN_OBJ) $(OBJ) $(READLINE_LIB)
		@echo "the executable $@ has been created"

$(LIBMINI): $(OBJ) $(LIBFT)
		ar rc  $@ $(OBJ) $(LIBFT)
		@echo "the libmini.a archieve has been created"

$(LIBFT):
		make -C ./libft all

%.o: %.c ./libminishell.h ./libtree.h
		$(CC) $(CFLAGS) -o $@ -c $< $(READLINE_INC)
		@echo "object $@ has been created from $<"



clean:
	$(RM) $(OBJ) $(MAIN_OBJ)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME) $(LIBMINI)
	make -C ./libft fclean
	
re: fclean all

.PHONY: clean fclean re $(NAME) $(LIBMINI) all
