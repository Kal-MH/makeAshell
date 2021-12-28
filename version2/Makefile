# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: napark <napark@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 17:02:38 by napark            #+#    #+#              #
#    Updated: 2021/12/29 01:38:14 by mkal             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	gcc
CFLAGS	=	-g -Wall -Wextra -Werror

# PATH
SRCS_PATH = srcs
CMD_PATH = $(SRCS_PATH)/cmd
EXECVE_PATH = $(SRCS_PATH)/execve
BUILTIN_PATH = $(EXECVE_PATH)/builtin
TERMINAL_PATH = $(SRCS_PATH)/terminal
TOKEN_PATH = $(SRCS_PATH)/tokenizer
UTIL_PATH = $(SRCS_PATH)/util
ENV_PATH = $(SRCS_PATH)/env

SRCS	=	$(SRCS_PATH)/main.c $(SRCS_PATH)/signal.c \
		$(TOKEN_PATH)/tokenizer.c $(TOKEN_PATH)/token_util.c \
		$(TOKEN_PATH)/token_util2.c $(TOKEN_PATH)/token_check.c \
		$(ENV_PATH)/env.c $(ENV_PATH)/env_util.c\
		$(ENV_PATH)/env_return_value.c\
		$(BUILTIN_PATH)/export.c $(BUILTIN_PATH)/export_util.c \
		$(BUILTIN_PATH)/ft_pwd.c $(BUILTIN_PATH)/ft_exit.c \
		$(BUILTIN_PATH)/ft_cd.c $(BUILTIN_PATH)/ft_echo.c \
		$(BUILTIN_PATH)/ft_unset.c $(BUILTIN_PATH)/ft_export.c \
		$(CMD_PATH)/cmd.c $(CMD_PATH)/cmd_parse.c \
		$(CMD_PATH)/cmd_check.c $(CMD_PATH)/cmd_util.c \
		$(CMD_PATH)/make_cmd_util.c \
		$(EXECVE_PATH)/path.c $(EXECVE_PATH)/execve.c $(EXECVE_PATH)/builtin.c \
		$(EXECVE_PATH)/execve_util.c $(EXECVE_PATH)/check_redirection.c\
		$(EXECVE_PATH)/execve_util2.c $(EXECVE_PATH)/check_cmd_dollar_sign.c\
		$(UTIL_PATH)/string_util.c $(UTIL_PATH)/get_next_line.c $(UTIL_PATH)/free.c \
		$(UTIL_PATH)/ft_str_func.c \
		$(TERMINAL_PATH)/press_arrow2.c $(TERMINAL_PATH)/term.c \
		$(TERMINAL_PATH)/cursor.c $(TERMINAL_PATH)/history.c \
		$(TERMINAL_PATH)/press_arrow.c $(TERMINAL_PATH)/prompt.c\

INCS	=	-I includes -I libft
OBJS	=	$(SRCS:.c=.o)
LIBFT	=	libft/libft.a
LFT		=	-L libft -lft -lncurses -lreadline

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFT) $(INCS)

$(LIBFT) :
	@make -C libft/

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

clean :
	@make clean -C libft/
	rm -rf $(OBJS)

fclean : clean
	@make fclean -C libft/
	rm -rf $(NAME)

re : fclean all
