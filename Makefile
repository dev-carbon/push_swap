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

# SANITIZE =		-g -fsanitize=address

RM = 			rm -rf

INC_CHECKER = 	-I./libft/ \
				-I./srcs/checker/includes/ \
				-I./srcs/checker/init/ \
				-I./srcs/checker/stack/ \
				-I./srcs/checker/utils/ \
				-I./srcs/checker/validate/ \

INC_PUSH_SWAP =	-I./libft/ \
				-I./srcs/push_swap/includes/ \
				-I./srcs/push_swap/init/ \
				-I./srcs/push_swap/stack/ \
				-I./srcs/push_swap/sort/ \
				-I./srcs/push_swap/utils/ \
				-I./srcs/push_swap/validate/ \

LIBFT = 			-Llibft -lft

SRCS_CHECKER =	$(wildcard ./srcs/checker/*.c) \
				$(wildcard ./srcs/checker/init/*.c) \
				$(wildcard ./srcs/checker/stack/*.c) \
				$(wildcard ./srcs/checker/utils/*.c) \
				$(wildcard ./srcs/checker/validate/*.c) \

SRCS_PUSH_SWAP =	$(wildcard ./srcs/push_swap/*.c) \
					$(wildcard ./srcs/push_swap/init/*.c) \
					$(wildcard ./srcs/push_swap/stack/*.c) \
					$(wildcard ./srcs/push_swap/sort/*.c) \
					$(wildcard ./srcs/push_swap/utils/*.c) \
					$(wildcard ./srcs/push_swap/validate/*.c) \

OBJS_CHECKER = 	$(SRCS_CHECKER: %.c=%.o)

OBJS_PUSH_SWAP =	$(SRCS_PUSH_SWAP: %.c=%.o)

all: 			$(PUSH_SWAP) #$(CHECKER) $(PUSH_SWAP)

$(CHECKER): 	$(OBJS_CHECKER)
				@$(MAKE) --directory=libft
				@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_CHECKER) -o $@ $^ $(LIBFT)
				@echo "\nProgramm $(CHECKER) created."

$(PUSH_SWAP): 	$(OBJS_PUSH_SWAP)
				@$(MAKE) --directory=libft
				@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_PUSH_SWAP) -o $@ $^ $(LIBFT)
				@echo "\nProgramm $(PUSH_SWAP) created."

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
