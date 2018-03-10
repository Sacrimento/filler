# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/10 17:01:23 by abouvero          #+#    #+#              #
#    Updated: 2018/03/10 17:02:40 by abouvero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abouvero.filler
LIBDIR = libft/
LIBFT = ./libft/libft.a
SRC = main.c \
	  parser.c \
	  resolve.c \
	  heat.c \
	  free.c \

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(FLAGS) -o $(NAME) $(LIBFT) $(OBJ)

$(LIBFT):
	make -C $(LIBDIR)

%.o:	%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all
