# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takra <takra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 22:02:20 by mohtakra          #+#    #+#              #
#    Updated: 2023/08/19 15:36:03 by takra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=MINISHELL
LIBMINI=libmini.a
LIBFT=./libft/libft.a
CC=cc
CFLAGS=
# CFLAGS=-Wall -Werror -Wextra
RM=rm -f
HEADERS=./libminishell.h ./libft/libft.h ./error_handler/liberror.h

# READLINE_INC = -I/goinfre/$(USER)/homebrew/opt/readline/include #linux
# READLINE_LIB = -lreadline -L/goinfre/$(USER)/homebrew/opt/readline/lib #linux

READLINE_INC = -I/goinfre/$(USER)/.brew/opt/readline/include		 	#MAC
READLINE_LIB = -lreadline -L/goinfre/$(USER)/.brew/opt/readline/lib    #MAC

PATHEXEC= ./execution/
PATHBUILT=$(PATHEXEC)builtins/
PATHERR=./error_handler/
PATHPARS= ./parsing/
# PATHTREE= ./tree/

SRC= $(PATHEXEC)prompt.c $(PATHEXEC)execution.c $(PATHEXEC)execute_list.c $(PATHEXEC)convert_env_to_list.c\
	 $(PATHBUILT)is_builtins.c $(PATHBUILT)builtins.c $(PATHBUILT)cd.c $(PATHBUILT)env_.c\
		$(PATHBUILT)is_variable_exists.c\
		$(PATHBUILT)get_variable_len.c $(PATHBUILT)get_variable_name.c $(PATHBUILT)get_variable_value.c\
	 	$(PATHBUILT)expend_data.c $(PATHBUILT)update_env_value.c\
		$(PATHBUILT)export.c $(PATHBUILT)pwd.c $(PATHBUILT)unset.c $(PATHBUILT)update_shlvl.c \
	 $(PATHERR)print_error.c \
	 $(PATHPARS)parse_data.c 
MAIN_SRC=minishell.c



OBJ=$(SRC:.c=.o)
MAIN_OBJ=$(MAIN_SRC:.c=.o)

all:$(NAME)

$(NAME) : $(OBJ) $(MAIN_OBJ) $(LIBMINI)
		$(CC)  -o $@ $(MAIN_OBJ) $(OBJ) $(LIBMINI) $(LIBFT) $(READLINE_LIB)
		@echo "the executable $@ has been created"

$(LIBMINI):$(LIBFT) $(OBJ) 
		ar rc  $@ $(OBJ) 
		@echo "the libmini.a archieve has been created"

$(LIBFT):
		make -C ./libft all

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) $(READLINE_INC) -o $@ -c $< 
		@echo "object $@ has been created from $<"



clean:
	$(RM) $(OBJ) $(MAIN_OBJ)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME) $(LIBMINI)
	make -C ./libft fclean
	
re: fclean all

.PHONY: clean fclean re $(NAME) $(LIBMINI) all
