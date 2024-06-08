NAME = so_Long_bonus
CC = cc -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
LIBS = ../../MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/asalmi/.brew/opt/glfw/lib"
RM = rm -rf

SRC = $(wildcard *.c) $(wildcard get_next_line/*c)
OBJC = $(SRC:.c=.o)

RED=\033[0;31m
PURPLE=\033[0;35m
NC=\033[0m

all : $(NAME)

$(NAME) : $(OBJC) so_Long_bonus.h
	@$(CC) $(CFLAGS) $(OBJC) $(LIBS) -o $@
	@echo "${PURPLE}BONUS DONE${NC}"

%.o : %.c so_Long_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJC)

fclean : clean
	@$(RM) $(NAME)
	@echo "${RED}CLEANING BONUS...${NC}"

re : fclean all

.PHONY : clean 
