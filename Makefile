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

# This is a minimal set of ANSI/VT100 color codes
_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

# Colors
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

CHECKER = checker

PUSH_SWAP = push_swap

CC = clang

CCFLAGS = -Wall -Wextra -Werror

# SANITIZE = -g -fsanitize=address

RM = rm -rf

INCLUDES = -Ilibft/ \
			-Iincludes/ \
			-Isrcs/checker/init/ \
			-Isrcs/checker/actions/ \
			-Isrcs/checker/utils/ \
			-Isrcs/checker/validate/ \

LIBS = -Llibft -lft

SRCS = srcs/checker/main.c \
		$(wildcard srcs/checker/actions/*.c) \
		$(wildcard srcs/checker/init/*.c) \
		$(wildcard srcs/checker/utils/*.c) \
		$(wildcard srcs/checker/validate/*.c) \

SRCS_BONUS = $(wildcard bonus/srcs/*.c)

OBJS = $(SRCS: %.c=%.o)

OBJS_BONUS = $(SRCS_BONUS: %.c=%.o)

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(OBJS)
	@$(MAKE) --directory=libft
	@$(CC) $(CCFLAGS) $(SANITIZE) $(INCLUDES) -o $@ $^ $(LIBS)
	@echo "\nProgramm $(CHECKER) created."

%.o:
	$(CC) $(CCFLAGS) -c $< -o $@ 

clean:
	@cd libft && $(MAKE) clean
	@$(RM) *.o

fclean: clean
	@cd libft && $(MAKE) fclean
	@$(RM) $(CHECKER) $(PUSH_SWAP)

re: fclean all

.PHONY: all bonus clean fclean re
