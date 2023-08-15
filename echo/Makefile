NAME=echo
LIBFT= ./../libft/libft.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
SRC =  echo.c

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): $(LIBFT)  $(OBJ)
		@$(CC) -o $@  $(OBJ) $(LIBFT)
		@echo "the executable of echo has been created"

%.o: %.c libecho.h
		@$(CC) $(CFLAGS) -o $@ -c $< 
		@echo "the file $@ has been created from $<"

$(LIBFT):
	make -C ./../libft all
clean:
		@$(RM) $(OBJ)
		make -C ./../libft clean
		@echo "all the .o has been deleted successfully"
fclean: clean
		@$(RM) $(NAME)
		make -C ./../libft fclean
		@echo "the executable echo has been deleted"
	
re: fclean all

.PHONY : clean $(NAME) all fclean bonus re