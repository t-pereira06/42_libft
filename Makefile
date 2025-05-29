# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:26:29 by tsodre-p          #+#    #+#              #
#    Updated: 2025/05/29 12:01:42 by tsodre-p         ###   ########.fr        #
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
CFLAGS = -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage -g
AR = ar rcs

OBJ = $(FUNCS:%.c=%.o)
BONUS_OBJ = $(BONUS:%.c=%.o)

# === GoogleTest ===
CXXTESTS = g++
TEST_DIR = tests
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)
BIN_DIR = tests/bin
TEST_BIN = $(BIN_DIR)/run_tests
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
		rm -rf $(BIN_DIR)
		sudo rm -rf coverage-report
		sudo rm -f coverage.info
		find . -name "*.gcda" -delete
		find . -name "*.gcno" -delete

tests: $(NAME)
	mkdir -p $(BIN_DIR)
	$(CXXTESTS) $(CFLAGS) $(TEST_SRC) -I. -L. -lft -o $(TEST_BIN) $(GTEST_FLAGS)

testclean:
	@$(RM) $(TEST_BIN)

coverage:
	lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch
	lcov --remove coverage.info '*/tests/*' '/usr/*' --output-file coverage.info
	genhtml coverage.info --output-directory coverage-report

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(FUNCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)
