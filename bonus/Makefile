NAME = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = ../../MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/asalmi/.brew/opt/glfw/lib"
RM = rm -rf

SRC = animation_bonus.c exit_bonus.c exit_remaining_bonus.c frams_bonus.c load_images_bonus.c \
	load_images_remaining_bonus.c main_bonus.c move_bonus.c parsing_bonus.c parsing_utils_bonus.c \
	path_finding_bonus.c print_elemnt_bonus.c print_map_bonus.c set_map_bonus.c utils2_function_bonus.c \
	utils3_function_bonus.c utils_function_bonus.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
OBJC = $(SRC:.c=.o)

RED=\033[0;31m
PURPLE=\033[0;35m
NC=\033[0m

all : $(NAME)

$(NAME) : $(OBJC) so_long_bonus.h
	@$(CC) $(CFLAGS) $(OBJC) $(LIBS) -o $@
	@echo "${PURPLE}BONUS DONE${NC}"

%.o : %.c so_long_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJC)

fclean : clean
	@$(RM) $(NAME)
	@echo "${RED}CLEANING BONUS...${NC}"

re : fclean all

.PHONY : clean 
