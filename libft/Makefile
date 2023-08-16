# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: takra <takra@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 18:37:53 by mohtakra          #+#    #+#              #
#    Updated: 2023/08/16 02:01:42 by takra            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC =  ft_atoi.c ft_isdigit.c ft_isalpha.c\
	ft_strdup.c ft_strjoin.c\
	ft_strchr.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strlcpy.c\
	ft_freematrix.c ft_split.c \
	ft_putchar_fd.c ft_putstr_fd.c\
	ft_putendl_fd.c ft_putnbr_fd.c

SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c  \
	ft_lstclear.c ft_lstdelone.c
	
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
all: $(NAME) bonus

$(NAME): $(OBJB) $(OBJ)
		@ar rc $@ $(OBJ) $(OBJB)
		@echo "the files has ben archived successfully"

%.o: %.c libft.h
		@$(CC) -o $@ -c $< $(CFLAGS)
		@echo "the file $@ has been created from $<"


clean:
		@$(RM) $(OBJ) $(OBJB)
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		@echo "the libft.a has been deleted"

bonus : $(OBJB)
		@ar rc $(NAME) $(OBJB)
		@echo "the file bonus has ben archived successfully"
	
re: fclean all

.PHONY : clean $(NAME) all fclean bonus re