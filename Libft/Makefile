# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frocha-b <frocha-b@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/07 17:24:13 by frocha-b          #+#    #+#              #
#    Updated: 2025/05/22 12:07:48 by frocha-b         ###   ########.fr        #
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

SRCS += ft_printf.c
SRCS += ft_printf_parsing.c
SRCS += ft_printf_utils.c
SCRS += ft_printf_utils_hex.c

SRCS_B = ft_lstnew_bonus.c
SRCS_B += ft_lstadd_front_bonus.c
SRCS_B += ft_lstsize_bonus.c
SRCS_B += ft_lstlast_bonus.c
SRCS_B += ft_lstadd_back_bonus.c
SRCS_B += ft_lstdelone_bonus.c
SRCS_B += ft_lstclear_bonus.c
SRCS_B += ft_lstiter_bonus.c
SRCS_B += ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

CC     = cc
CFLAGS = -Wall -Werror -Wextra
LIBC   = ar -rcs
RM     = rm -f
INCS   = .

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME) : $(OBJS)
	${LIBC} $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME) $(OBJS_B)
		${LIBC} $(NAME) $(OBJS_B)

clean :
	 rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME) $(bonus)

re : fclean all