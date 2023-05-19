# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgasparo <jgasparo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 13:44:57 by jgasparo          #+#    #+#              #
#    Updated: 2023/05/16 14:33:45 by jgasparo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME):	$(OBJ)
	$(LIB) $(OBJ)

clean:
	@$(REMOVE) $(OBJ)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re