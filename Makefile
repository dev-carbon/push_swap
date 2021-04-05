# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/04 12:04:48 by humanfou          #+#    #+#              #
#    Updated: 2021/04/04 12:04:50 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

PUSH_SWAP = push_swap

CC = clang

CCFLAGS = -Wall -Wextra -Werror

# SANITIZE = -g -fsanitize=address

INCLUDES = -Ilibft/ \
			-Iincludes/ \
			-Isrcs/init/ \
			-Isrcs/actions/ \
			-Isrcs/utils/ \
			-Isrcs/validate/ \

LIBS = -Llibft -lft

SRCS = main.c \
		srcs/checker.c \
		$(wildcard srcs/actions/*.c) \
		$(wildcard srcs/init/*.c) \
		$(wildcard srcs/utils/*.c) \
		$(wildcard srcs/validate/*.c) \

SRCS_BONUS = $(wildcard bonus/srcs/*.c)

OBJS = $(SRCS: %.c=%.o)

OBJS_BONUS = $(SRCS_BONUS: %.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --directory=libft
	$(CC) $(CCFLAGS) $(SANITIZE) $(INCLUDES) -o $@ $^ $(LIBS)

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS)
	$(CC) $(CCFLAGS) $(INCLUDES) -o $@ $^

%.o:
	$(CC) $(CCFLAGS) -c $< -o $@ 

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME) $(PUSH_SWAP) a.out

re: fclean all

.PHONY: all bonus clean fclean re