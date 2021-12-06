CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address -Qunused-arguments `pkg-config --libs --cflags readline`

NAME = minishell

SRCS =	main.c\
		parsing.c\
		init.c\

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC $(CFLAGS) -c $< -o $@ -I ./

$(NAME): $(OBJS)
	@ make bonus -C ./lib/libft/
	$(CC) $(CFLAGS) -I ./ $^ -o $@ ./lib/libft/libft.a

all: $(NAME)

clean:
	rm -rf $(OBJS)
	@ make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	@ make fclean -C ./libft

re: fclean all