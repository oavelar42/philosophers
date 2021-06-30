# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 11:12:25 by oavelar           #+#    #+#              #
#    Updated: 2021/06/30 21:49:37 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang -Wall -Wextra -Werror -pthread -fsanitize=address
RM			= rm -rf
NAME		= ./philo
NAME_SHORT	= philo

INCS_DIR	= includes
MAIN_INC	= -I$(INCS_DIR)
INCS		= $(shell find $(INCS_DIR) -type f -name "*.h")

SRCS_DIR 	= srcs
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.c")

OBJS		= $(SRCS:.c=.o)

_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]

%.o			: %.c
			@echo "[..] $(NAME_SHORT)... compiling $*.c\r\c"
			@$(CC) $(MAIN_INC) -c $< -o $@
			@echo "$(_CLEAR)"

all			: $(NAME)

$(NAME)		: $(OBJS) $(OBJS_UTILS) $(INCS)
			@$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)
			@echo "$(_OK) $(NAME_SHORT) compiled"

clean		:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

norme		:
			@norminette $(SRCS) $(INCS)

.PHONY		: all clean fclean re norme