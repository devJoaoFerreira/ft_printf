# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jnovo-fe <jnovo-fe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 14:29:32 by jnovo-fe          #+#    #+#              #
#    Updated: 2025/12/18 14:39:08 by jnovo-fe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_parse.c ft_convert_cs.c ft_convert_di.c ft_convert_p.c ft_convert_percentage.c ft_convert_u.c ft_convert_xX.c ft_fill_struct.c ft_conversion_helpers.c ft_conversion_helpers2.c
BONUS_SRC = 
OBJ = $(SRC:.c=.o)
BONUS_OBJ = 
HEADER = libftprintf.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

main: main.c $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME)

bonus: all

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re