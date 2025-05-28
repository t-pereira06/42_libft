# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:26:29 by tsodre-p          #+#    #+#              #
#    Updated: 2025/05/28 21:10:55 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FUNCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

CC = cc -g
RM = rm -f
CFLAG = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(FUNCS:%.c=%.o)
BONUS_OBJ = $(BONUS:%.c=%.o)

# === GoogleTest ===
CXXTESTS = g++
TEST_DIR = tests
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
TEST_BIN = run_tests
GTEST_FLAGS = -lgtest -lgtest_main -pthread
# ==================

all: $(NAME) tests

$(NAME): $(OBJ)
		@$(AR) $(NAME) $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
		@$(AR) $(NAME) $(BONUS_OBJ) $(OBJ)

compile: bonus
		@$(CC) $(CFLAGS) $(FUNCS)

clean:
		@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean testclean
		@$(RM) $(NAME)

tests: $(NAME)
	$(CXXTESTS) $(CFLAG) $(TEST_SRC) -I. -L. -lft -o $(TEST_BIN) $(GTEST_FLAGS)

testclean:
	@$(RM) $(TEST_BIN)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(FUNCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)
