# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 13:44:57 by jgasparo          #+#    #+#              #
#    Updated: 2023/05/24 15:54:12 by jgasparo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
ft_calloc.c \
ft_putchar_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_strlen.c \
ft_memset.c \

#SRC_LIBFT = ../libft/libft.a


OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME):	$(OBJ)
	$(LIB) $(OBJ) 
#$(SRC_LIBFT)

clean:
	@$(REMOVE) $(OBJ)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re