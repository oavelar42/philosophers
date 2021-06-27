# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oavelar <oavelar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 11:12:25 by oavelar           #+#    #+#              #
#    Updated: 2021/06/27 19:16:57 by oavelar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo

CC 		= gcc 

FLAGS	= -Wall -Wextra -Werror -fsanitize=address

INCLUDE = -I ./includes/

SRC_ONE	= philo/

SRCS 	= 	main.c \
			utils.c \
			parse.c \
			init.c

OBJ		=	$(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

GREEN		= \033[1;32m
BLUE		= \033[0;34m
RED		= \033[1;31m
COLOR_OFF	= \033[0m

$(NAME)	: $(OBJ)
	@echo "$(BLUE)Init Philosophers$(COLOR_OFF)"
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) -l pthread -o $(NAME)
	@echo "$(GREEN)Philo done...$(COLOR_OFF)"

all		: $(NAME)

clean	:
	@make clean $(OBJ)
	@rm -f $(OBJ)
	@echo "$(RED)...Objects removed...$(COLOR_OFF)"

fclean	: clean
	@make fclean $(OBJ) 
	@rm -rf $(NAME)
	@echo "$(RED)....All cleared....$(COLOR_OFF)"

re		: fclean all

.PHONY	: all clean fclean re 