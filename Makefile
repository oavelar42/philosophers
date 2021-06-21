# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 11:12:25 by oavelar           #+#    #+#              #
#    Updated: 2021/06/21 11:32:29 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo_one

CC 		= gcc -g

FLAGS	= -Wall - Wextra -Werror

SRC_ONE	= philo_one

SRCS 	= main.c \

SRC		= $(addprefix $(SRC_ONE), $(SRCS))

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED		= \033[1;31m
COLOR_OFF	= \033[0m

all		: $(NAME)

$(NAME)	: $(OBJ)
	@echo "$(BLUE)Init Philosophers$(COLOR_OFF)"
	$(CC) $(FLAGS) $(SRC) -l pthread -o $(NAME)
	@echo "$(GREEN)Philo done...$(COLOR_OFF)"

clean	:
	rm -rf $(OBJ)

fclean	: clean
	rm -rf $(NAME)

re		: fclean all

.PHONY	: all clean fclean re 