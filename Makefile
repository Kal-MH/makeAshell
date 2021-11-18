# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 16:20:05 by mkal              #+#    #+#              #
#    Updated: 2021/11/18 17:12:33 by mkal             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
INCS_DIR = ./include/
SRCS_DIR = ./srcs/

LIB = ./lib
GNL = get_next_line
LIBFT = libft

GCC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = main.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))
OBJS = $(SRCS:.c=.o)

.c.o:
	$(GCC) $(CFLAGS) -I$(INCS_DIR) -o $@ -c $?

$(NAME): $(OBJS)
	make -C $(LIB)/$(LIBFT)
	make -C $(LIB)/$(GNL)
	$(GCC) $(CFLAGS) $(OBJS) -o $(NAME) -I $(INCS_DIR) -L $(LIB)/$(GNL) -lgnl -L $(LIB)/$(LIBFT) -lft

all: $(NAME)

clean:
	make -C $(LIB)/$(GNL) clean
	make -C $(LIB)/$(LIBFT) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIB)/$(GNL) fclean
	make -C $(LIB)/$(LIBFT) fclean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
