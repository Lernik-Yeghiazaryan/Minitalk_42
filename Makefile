NAME1	= server
NAME2	= client
SRCS	= $(shell find "." -name "*.c")
OBJC	= $(SRCS:.c=.o)
CC		= gcc
RM		= rm -f
CFLAGS	= -Wextra -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJC)
	$(CC) $(CFLAGS) s_server.o -o $(NAME1)

$(NAME2): $(OBJC)
	$(CC) $(CFLAGS) c_client.o -o $(NAME2)

clean:
	$(RM) $(OBJC)

fclean:	clean
	$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re