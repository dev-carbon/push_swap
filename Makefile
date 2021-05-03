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

GREY =				\e[30m
RED = 				\e[31m
GREEN =				\e[32m
YELLOW =			\e[33m
BLUE =				\e[34m
PURPLE =			\e[35m
CYAN =				\e[36m
WHITE =				\e[37m
BOLD =				\e[1m
RESET =				\e[0m

CC = 				clang

CCFLAGS = 			-Wall -Wextra -Werror -g3

SANITIZE =			-g -fsanitize=address

RM = 				rm -rf

CHECKER =			checker

CHECKER_BONUS = 	checker_bonus

PUSH_SWAP = 		push_swap

PUSH_SWAP_BONUS = 	push_swap_bonus

INC_COMMON =		-I./libft/ \
					-I./includes/ \
					-I./srcs/common/stack/ \
					-I./srcs/common/sort/ \
					-I./srcs/common/utils/ \
					-I./srcs/common/validate/ \

INC_MANDATORY = 	-I./srcs/mandatory/init/ \
					-I./srcs/mandatory/validate/ \

INC_BONUS =			-I./srcs/bonus/display/ \
					-I./srcs/bonus/init/ \
					-I./srcs/bonus/validate/ \

LIBFT = 			-Llibft -lft

SRCS_COMMON =		$(wildcard ./srcs/common/stack/*.c) \
					$(wildcard ./srcs/common/sort/*.c) \
					$(wildcard ./srcs/common/utils/*.c) \
					$(wildcard ./srcs/common/validate/*.c) \

SRCS_MANDATORY =	./srcs/mandatory/init/init_vars.c \
					./srcs/mandatory/validate/is_valid_args.c \

SRCS_BONUS =		$(wildcard ./srcs/bonus/display/*.c) \
					./srcs/bonus/init/init_vars_bonus.c \
					./srcs/bonus/validate/is_valid_args_bonus.c \
					./srcs/bonus/validate/is_valid_options_bonus.c \

SRCS_CHECKER_MANDATORY =	./srcs/mandatory/drivers/checker.c

SRCS_CHECKER_BONUS =	./srcs/bonus/drivers/checker_bonus.c

SRCS_PUSH_SWAP_MANDATORY =	./srcs/mandatory/drivers/push_swap.c

SRCS_PUSH_SWAP_BONUS =	./srcs/bonus/drivers/push_swap_bonus.c

OBJS_COMMON =		$(SRCS_COMMON: %.c=%.o)

OBJS_MANDATORY =	$(SRCS_MANDATORY: %.c=%.o)

OBJS_BONUS =		$(SRCS_BONUS: %.c=%.o)

OBJS_CHECKER_MANDATORY = $(SRCS_CHECKER_MANDATORY: %.c=%.o)

OBJS_CHECKER_BONUS = 	$(SRCS_CHECKER_BONUS: %.c=%.o)

OBJS_PUSH_SWAP_MANDATORY =	$(SRCS_PUSH_SWAP_MANDATORY: %.c=%.o)

OBJS_PUSH_SWAP_BONUS =	$(SRCS_PUSH_SWAP_BONUS: %.c=%.o)

all: 				$(CHECKER) $(PUSH_SWAP)

bonus:				$(CHECKER_BONUS) $(PUSH_SWAP_BONUS)

$(CHECKER): 		$(OBJS_COMMON) $(OBJS_MANDATORY) $(OBJS_CHECKER_MANDATORY)
					@$(MAKE) --directory=libft
					@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_COMMON) $(INC_MANDATORY) -o $@ $^ $(LIBFT)
					@echo "${BLUE}\nProgramm $(CHECKER) created.\n${RESET}"

$(PUSH_SWAP): 		$(OBJS_COMMON) $(OBJS_MANDATORY) $(OBJS_PUSH_SWAP_MANDATORY)
					@$(MAKE) --directory=libft
					@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_COMMON) $(INC_MANDATORY) -o $@ $^ $(LIBFT)
					@echo "${BLUE}\nProgramm $(PUSH_SWAP) created.\n${RESET}"

$(CHECKER_BONUS): 	$(OBJS_COMMON) $(OBJS_BONUS) $(OBJS_CHECKER_BONUS)
					@$(MAKE) --directory=libft
					@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_COMMON) $(INC_BONUS) -o $@ $^ $(LIBFT)
					@echo "${BLUE}\nProgramm $@ created.\n${RESET}"

$(PUSH_SWAP_BONUS): $(OBJS_COMMON) $(OBJS_BONUS) $(OBJS_PUSH_SWAP_BONUS)
					@$(MAKE) --directory=libft
					@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_COMMON) $(INC_BONUS) -o $@ $^ $(LIBFT)
					@echo "${BLUE}\nProgramm $(PUSH_SWAP) created.\n${RESET}"

%.o:
					$(CC) $(CCFLAGS) -c $< -o $@

clean:
					@cd libft && $(MAKE) clean
					@$(RM) *.o

fclean: 			clean
					@cd libft && $(MAKE) fclean
					@$(RM) $(CHECKER) $(PUSH_SWAP) $(CHECKER_BONUS) $(PUSH_SWAP_BONUS)

re:		 			fclean all

.PHONY: 			all bonus clean fclean re
