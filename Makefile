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

ifneq (,$(findstring xterm,${TERM}))
	BLACK        	:= $(shell tput -Txterm setaf 0)
	RED          	:= $(shell tput -Txterm setaf 1)
	GREEN        	:= $(shell tput -Txterm setaf 2)
	YELLOW       	:= $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  	:= $(shell tput -Txterm setaf 4)
	PURPLE       	:= $(shell tput -Txterm setaf 5)
	BLUE			:= $(shell tput -Txterm setaf 6)
	WHITE        	:= $(shell tput -Txterm setaf 7)
	RESET 			:= $(shell tput -Txterm sgr0)
	BOLD			:= $(shell tput -Txterm bold)
else
	BLACK        	:= ""
	RED          	:= ""
	GREEN        	:= ""
	YELLOW       	:= ""
	LIGHTPURPLE  	:= ""
	PURPLE       	:= ""
	BLUE        	:= ""
	WHITE        	:= ""
	RESET        	:= ""
endif

CHECKER =			checker

PUSH_SWAP = 		push_swap

CC = 				clang

CCFLAGS = 			-Wall -Wextra -Werror -g3

SANITIZE =		-g -fsanitize=address

RM = 				rm -rf

INC_COMMON =		-I./libft/ \
					-I./includes/ \
					-I./srcs/init/ \
					-I./srcs/stack/ \
					-I./srcs/utils/ \
					-I./srcs/validate/ \

INC_CHECKER =		-I./srcs/drivers/checker \

INC_PUSH_SWAP =		-I./srcs/drivers/push_swap \
					-I./srcs/sort/ \

INC_BONUS =			-I./srcs/bonus/drivers/checker \
					-I./srcs/bonus/drivers/push_swap \

LIBFT = 			-Llibft -lft

SRCS_COMMON =		$(wildcard ./srcs/init/*.c) \
					$(wildcard ./srcs/stack/*.c) \
					$(wildcard ./srcs/utils/*.c) \
					$(wildcard ./srcs/validate/*.c) \

SRCS_CHECKER =		$(wildcard ./srcs/drivers/checker/checker.c) \

SRCS_PUSH_SWAP =	$(wildcard ./srcs/drivers/push_swap/push_swap.c) \
					$(wildcard ./srcs/sort/*.c) \

SRCS_CHECKER_BONUS =	$(wildcard ./srcs/drivers/checker_bonus.c) \

SRCS_PUSH_SWAP_BONUS =	$(wildcard ./srcs/drivers/push_swap_bonus.c) \

OBJS_COMMON =		$(SRCS_COMMON: %.c=%.o)

OBJS_CHECKER = 		$(SRCS_CHECKER: %.c=%.o)

OBJS_PUSH_SWAP =	$(SRCS_PUSH_SWAP: %.c=%.o)

OBJS_BONUS = 		$(SRCS_BONUS: %.c=%.o)

all: 				$(CHECKER) $(PUSH_SWAP)

bonus:				$(CHECKER_BONUS) $(PUSH_SWAP_BONUS)

$(CHECKER): 		$(OBJS_COMMON) $(OBJS_CHECKER)
					@$(MAKE) --directory=libft
					@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_COMMON) $(INC_CHECKER) -o $@ $^ $(LIBFT)
					@echo "${BOLD}${BLUE}\nProgramm $(CHECKER) created.\n${RESET}"

$(PUSH_SWAP): 		$(OBJS_COMMON) $(OBJS_PUSH_SWAP)
					@$(MAKE) --directory=libft
					@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_COMMON) $(INC_PUSH_SWAP) -o $@ $^ $(LIBFT)
					@echo "${BOLD}${BLUE}\nProgramm $(PUSH_SWAP) created.\n${RESET}"

$(CHECKER_BONUS): 	$(OBJS_COMMON) $(OBJS_CHECKER_BONUS)
					@$(MAKE) --directory=libft
					@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_COMMON) $(INC_BONUS) -o $@ $^ $(LIBFT)
					@echo "${BOLD}${BLUE}\nProgramm $(CHECKER) created.\n${RESET}"

$(PUSH_SWAP_BONUS): $(OBJS_COMMON) $(OBJS_PUSH_SWAP_BONUS)
					@$(MAKE) --directory=libft
					@$(CC) $(CCFLAGS) $(SANITIZE) $(INC_COMMON) $(INC_BONUS) -o $@ $^ $(LIBFT)
					@echo "${BOLD}${BLUE}\nProgramm $(PUSH_SWAP) created.\n${RESET}"

%.o:
					$(CC) $(CCFLAGS) -c $< -o $@

clean:
					@cd libft && $(MAKE) clean
					@$(RM) *.o

fclean: 			clean
					@cd libft && $(MAKE) fclean
					@$(RM) $(CHECKER) $(PUSH_SWAP)

re:		 			fclean all

.PHONY: 			all bonus clean fclean re
