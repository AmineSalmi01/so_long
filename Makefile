NAME = so_Long
CC = cc -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
LIBS = ../MLX42/build/libmlx42.a -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/asalmi/.brew/opt/glfw/lib"
RM = rm -rf

SRC = $(wildcard *.c) $(wildcard get_next_line/*c)
OBJC = $(SRC:.c=.o)

all : $(NAME)


$(NAME) : $(OBJC) so_Long.h
	$(CC) $(CFLAGS) $(OBJC) $(LIBS) -o $@

%.o : %.c so_Long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJC)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean 
