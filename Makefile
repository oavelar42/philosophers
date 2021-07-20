# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 11:12:25 by oavelar           #+#    #+#              #
#    Updated: 2021/07/20 16:53:28 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang -Wall -Wextra -Werror -pthread #-fsanitize=address
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
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_RED		= \033[1;31m
_OFF		= \033[0m

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
			@echo "${_RED}...Removing object files...${_OFF}"

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

norme		:
			@norminette $(SRCS) $(INCS)

.PHONY		: all clean fclean re norme