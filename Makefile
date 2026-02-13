# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frocha-b <frocha-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/01 16:59:12 by frocha-b          #+#    #+#              #
#    Updated: 2026/02/13 17:41:33 by frocha-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

# Compiler and flags
CC 			= cc
CFLAGS		= -Wall -Werror -Wextra -g
MAKEFLAGS += --no-print-directory


# Libft
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_INC	= -I$(LIBFT_DIR)

# Directories
SRC_DIR 	= src
OBJ_DIR 	= objects

SRC_FILES 	= $(shell find $(SRC_DIR) -name "*.c")
OBJS 		= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Includes
MINISHELL_INC	= -Iincludes $(LIBFT_INC)

# Colors
C_GREEN		= \033[0;32m
C_YELLOW	= \033[1;33m
C_BLUE		= \033[0;34m	
C_RESET		= \033[0m

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all:  $(LIBFT) $(NAME)


$(NAME): $(OBJS)
	@echo "$(C_BLUE)🔗 Linking...$(C_RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline
	@echo "$(C_GREEN)✅ Built $(NAME)!$(C_RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(C_YELLOW)🛠️  Compiling $<$(C_RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ $(MINISHELL_INC)

$(LIBFT):
	@echo "$(C_BLUE)📚 Building libft...$(C_RESET)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

clean:
	@echo "$(C_BLUE)🧹 Cleaning object files...$(C_RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(C_BLUE)🧽 Removing executable...$(C_RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=sup_read ./minishell

.PHONY: all clean fclean re valgrind
