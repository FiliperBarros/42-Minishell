# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 17:24:13 by frocha-b          #+#    #+#              #
#    Updated: 2025/09/25 17:34:49 by frocha-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_isalnum.c
SRCS += ft_isascii.c
SRCS += ft_isprint.c
SRCS += ft_strlen.c
SRCS += ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_strlcpy.c
SRCS += ft_strlcat.c
SRCS += ft_toupper.c
SRCS += ft_tolower.c
SRCS += ft_strchr.c
SRCS += ft_strrchr.c
SRCS += ft_strncmp.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_strnstr.c
SRCS += ft_atoi.c
SRCS += ft_calloc.c
SRCS += ft_strdup.c
SRCS += ft_substr.c
SRCS += ft_strjoin.c
SRCS += ft_strtrim.c
SRCS += ft_split.c
SRCS += ft_itoa.c
SRCS += ft_strmapi.c
SRCS += ft_striteri.c
SRCS += ft_putchar_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c

SRCS += ft_printf/ft_printf.c
SRCS += ft_printf/ft_printf_parsing.c
SRCS += ft_printf/ft_printf_utils.c
SRCS += ft_printf/ft_printf_utils_hex.c

SRCS += get_next_line/get_next_line.c
SRCS += get_next_line/get_next_line_utils.c

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

OBJ_DIR = objects

CC     = cc
CFLAGS = -Wall -Werror -Wextra
LIBC   = ar -rcs

all : $(NAME)

$(NAME) : $(OBJS)
	${LIBC} $(NAME) $(OBJS)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@

clean :
	 rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)
	
re : fclean all