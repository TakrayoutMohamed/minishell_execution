# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takra <takra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/29 22:02:20 by mohtakra          #+#    #+#              #
#    Updated: 2023/09/14 05:12:00 by takra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libmini.a
LIBFT=./libft/libft.a
CC=cc
CFLAGS=-Wall -Werror -Wextra
RM=rm -f
HEADERS=./libminishell.h ./libft/libft.h ./error_handler/liberror.h

READLINE_INC =-I/goinfre/$(USER)/.brew/opt/readline/include
READLINE_LIB =-lreadline -L/goinfre/$(USER)/.brew/opt/readline/lib

PATHPIPE=./pipex/
PATHEXEC= ./execution/
PATHBUILT=$(PATHEXEC)builtins/
PATHERR=./error_handler/

SRC= $(PATHEXEC)execution.c $(PATHEXEC)execute_list.c \
	 $(PATHEXEC)convert_env_to_list.c $(PATHEXEC)get_path_of_cmd.c $(PATHEXEC)set_status.c\
	 $(PATHEXEC)kill_child_proccs.c\
	 $(PATHEXEC)convert_list_to_matrix.c $(PATHEXEC)convert_matrix_to_list.c\
		$(PATHBUILT)is_builtins.c $(PATHBUILT)is_cd.c $(PATHBUILT)is_echo.c $(PATHBUILT)is_env.c\
		$(PATHBUILT)is_exit.c $(PATHBUILT)is_export.c $(PATHBUILT)is_pwd.c $(PATHBUILT)is_unset.c\
		$(PATHBUILT)cd.c $(PATHBUILT)env_.c \
		$(PATHBUILT)echo.c $(PATHBUILT)exit_.c  $(PATHBUILT)is_variable_exists.c\
		$(PATHBUILT)get_variable_len.c $(PATHBUILT)get_variable_name.c $(PATHBUILT)get_variable_value.c\
	 	$(PATHBUILT)update_env_value.c $(PATHBUILT)print_export.c $(PATHBUILT)ft_lstswap.c \
	 	$(PATHBUILT)is_valid_identifier.c\
		$(PATHBUILT)export.c $(PATHBUILT)pwd.c $(PATHBUILT)unset.c $(PATHBUILT)update_shlvl.c\
		$(PATHBUILT)builtins_no_output.c \
	 $(PATHPIPE)pipe_beginning.c $(PATHPIPE)pipe_middle.c $(PATHPIPE)pipe_end.c $(PATHPIPE)pipe_builtins.c\
	 	$(PATHPIPE)read_from_fd.c $(PATHPIPE)close_pipe.c \
	 $(PATHERR)print_error.c $(PATHERR)print_strerror_set_status.c\
	 $(PATHERR)print_error_notfound.c $(PATHERR)print_error_nofiledir.c $(PATHERR)print_error_permission.c



OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(LIBFT) $(OBJ)
		@ar rc  $@ $(OBJ) $(LIBFT)
		@echo "the libmini.a archieve has been created"

$(LIBFT):
		make -C ./libft all

%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) $(READLINE_INC) -o $@ -c $< 
		@echo "object $@ has been created from $<"



clean:
	$(RM) $(OBJ)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	make -C ./libft fclean
	
re: fclean all

.PHONY: clean fclean re $(LIBFT) $(NAME) all
