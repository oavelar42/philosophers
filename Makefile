# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 11:12:25 by oavelar           #+#    #+#              #
#    Updated: 2021/06/21 18:02:17 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo_one

CC 		= gcc 

FLAGS	= -Wall -Wextra -Werror

SRC_ONE	= philo/

SRCS 	= 	main.c \
			utils.c \
			parse.c

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
	make clean -C $(OBJ)

fclean	: clean
	rm -rf $(NAME)
	@echo "\033[0;31m ---- all cleared! ---- \033[0m"

re		: fclean all

.PHONY	: all clean fclean re 