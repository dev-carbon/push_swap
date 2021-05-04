# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: humanfou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    created: 2020/09/23 17:49:24 by humanfou          #+#    #+#              #
#    Updated: 2021/04/17 16:38:32 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREY =				\e[0;30m
RED = 				\e[0;31m
GREEN =				\e[0;32m
YELLOW =			\e[0;33m
BLUE =				\e[0;34m
PURPLE =			\e[0;35m
CYAN =				\e[0;36m
WHITE =				\e[0;37m
BOLD =				\e[0;1m
RESET =				\e[0m

NAME = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

LIB = ar rc

SRCS = get_next_line.c \
	ft_print_split.c \
    ft_swap.c \
	ft_putstrnl.c \
	ft_strncpy.c \
	ft_strremove_spaces.c \
	ft_nbr_to_string.c \
	ft_split_len.c \
	ft_min.c \
	ft_max.c \
	ft_memset.c \
	ft_memalloc.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_charlen.c \
	ft_nbrlen.c \
	ft_isalpha.c \
	ft_islower.c \
	ft_isupper.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_strndup.c \
    ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strrtrim.c \
	ft_split.c \
	ft_strrev.c \
	ft_strnew.c \
	ft_itoa.c \
	ft_itoa_base.c \
	ft_strmapi.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putnbr.c \
	ft_putnbrmax_fd.c \
	ft_putnbrumax_fd.c 

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJ = $(SRCS:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all: bonus

bonus: $(OBJ) $(OBJ_BONUS)
	@$(LIB) $(NAME) $^
	@echo "${BOLD}${GREEN}${NAME} created.${RESET}"

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS)
	@$(LIB) $(NAME) $(OBJ)

clean:
	@/bin/rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "${BOLD}${YELLOW}Cleaned libft object files.${RESET}"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "${BOLD}${YELLOW}${NAME} removed.${RESET}"


re: fclean all

.PHONY = all bonus clean fclean re
