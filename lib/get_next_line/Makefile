# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkal <mkal@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 16:17:14 by mkal              #+#    #+#              #
#    Updated: 2021/11/18 16:52:54 by mkal             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

INCS_DIR = ../include/

GCC = gcc
GFLAGS = -Wall -Werror -Wextra

AR = ar rcs

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(GCC) $(GFLAGS) -I $(INCS_DIR) -c  $^ -o $@
	$(AR) $(NAME) $@

$(NAME): $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

all: $(NAME)

re: fclean all

.PHONY: all clean fclean re
