# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smoreron <7353718@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 03:05:45 by smoreron          #+#    #+#              #
#    Updated: 2024/02/14 03:05:45 by smoreron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   libft.a
SRCS    =   ft_isalpha.c    ft_strlcpy.c    ft_strtrim.c\
            ft_isdigit.c    ft_strlen.c     ft_split.c\
            ft_isalnum.c    ft_strlcat.c    ft_strmapi.c\
            ft_isascii.c    ft_strncmp.c    ft_striteri.c\
            ft_isprint.c    ft_strchr.c     ft_putchar_fd.c\
            ft_toupper.c    ft_strrchr.c    ft_putstr_fd.c\
            ft_tolower.c    ft_memchr.c     ft_putendl_fd.c\
            ft_atoi.c       ft_memcmp.c     ft_putnbr_fd.c\
            ft_itoa.c       ft_calloc.c     ft_strdup.c\
            ft_bzero.c      ft_substr.c     ft_memcpy.c\
            ft_strjoin.c    ft_memset.c     ft_memmove.c\
            ft_strnstr.c    ft_printf.c     ft_put_util.c
HEADER  =   libft.h
OBJ_DIR =   obj/
OBJ     =   $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
CC      =   cc
CFLAGS  =   -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o: %.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@rm -rf $(OBJ_DIR)

re: fclean all
