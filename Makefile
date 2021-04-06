# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 01:12:01 by humanfou          #+#    #+#              #
#    Updated: 2021/04/06 01:12:05 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = 		checker

PUSH_SWAP = 	push_swap

CC = 			clang

CCFLAGS = 		-Wall -Wextra -Werror -g3

SANITIZE =		-g -fsanitize=address

RM = 			rm -rf

INCLUDES = 		-I./libft/ \
				-I./includes/ \
				-I./srcs/checker/init/ \
				-I./srcs/checker/stack/ \
				-I./srcs/checker/utils/ \
				-I./srcs/checker/validate/ \

LIBS = 			-Llibft -lft

SRCS_CHECKER =	$(wildcard ./srcs/checker/*.c) \
				$(wildcard ./srcs/checker/init/*.c) \
				$(wildcard ./srcs/checker/stack/*.c) \
				$(wildcard ./srcs/checker/utils/*.c) \
				$(wildcard ./srcs/checker/validate/*.c) \

OBJS_CHECKER = 	$(SRCS_CHECKER: %.c=%.o)


all: 			$(CHECKER) #$(PUSH_SWAP)

$(CHECKER): 	$(OBJS_CHECKER)
				@$(MAKE) --directory=libft
				@$(CC) $(CCFLAGS) $(SANITIZE) $(INCLUDES) -o $@ $^ $(LIBS)
				@echo "\nProgramm $(CHECKER) created."

%.o:
				$(CC) $(CCFLAGS) -c $< -o $@ 

clean:
				@cd libft && $(MAKE) clean
				@$(RM) *.o

fclean: 		clean
				@cd libft && $(MAKE) fclean
				@$(RM) $(CHECKER) $(PUSH_SWAP)

re: 			fclean all

.PHONY: 		all bonus clean fclean re
