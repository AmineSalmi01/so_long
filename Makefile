NAME = so_Long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx 
RM = rm -rf

SRC = $(wildcard *.c)
OBJC = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJC) so_Long.h
	$(CC) $(CFLAGS) $(OBJC)  -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@

%.o : %.c so_Long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJC)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean
