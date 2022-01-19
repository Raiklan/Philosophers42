# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saich <saich@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 14:27:48 by saich             #+#    #+#              #
#    Updated: 2022/01/19 14:27:52 by saich            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
INCLUDE = philo.h\

INC_PATH = ./includes/

vpath %.c sources/

FILES =		./sources/main\
			./sources/parser/parsing\
			./sources/parser/ft_atoi\
			./sources/parser/utils\
			./sources/parser/print\
			./sources/execution/philo\
			./sources/execution/threads\
			./sources/execution/philo_utils\

SRCS = $(addsuffix .c, $(FILES))
OBJ = $(SRCS:.c=.o)

CC = gcc
L_CC = clang
FLAGS = -Wall -Wextra -Werror -fsanitize=thread
LIB = -lpthread
### COLORS ###

NOC = \033[0m
BOLD = \033[1m
UNDERLINE = \033[4m
BLACK = \033[1;30m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
VIOLET = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@echo "$(CYAN)Constructing executable:$(NOC) $@"
			@$(L_CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

.c.o:		${SRCS}
			@echo " $(VIOLET)[$(L_CC)] $(GREEN)[$(FLAGS)]$(NOC) $(YELLOW)in progress ...:$(NOC) $< $(RED)->$(NOC) $@"
			@$(L_CC) $(FLAGS) -c -I$(INC_PATH) $< -o ${<:.c=.o}
clean:
	@echo "\n$(RED)Removing '.o' objects: $(NOC) $@"
	@rm -f $(OBJ)

fclean: clean
	@echo "\n$(RED)Removing executable: $(NOC) $@"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean re fclean
