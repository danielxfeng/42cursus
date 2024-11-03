# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Xifeng <xifeng@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/25 19:36:06 by Xifeng            #+#    #+#              #
#    Updated: 2024/11/03 19:50:01 by Xifeng           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = libft.h

SRCS = ft_atoi.c ft_isascii.c ft_lstadd_front.c ft_lstmap.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
ft_bzero.c ft_isdigit.c ft_lstclear.c ft_lstnew.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
ft_calloc.c ft_isprint.c ft_lstdelone.c ft_lstsize.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
ft_isalnum.c ft_itoa.c ft_lstiter.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
ft_isalpha.c ft_lstadd_back.c ft_lstlast.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c 

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
