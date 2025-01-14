# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brogalsk <brogalsk@student.42warsaw.p      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 13:22:45 by brogalsk          #+#    #+#              #
#    Updated: 2024/03/17 11:44:49 by brogalsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = 		ft_printf.c\
 			ft_hexalower_pf.c\
			ft_putchar_pf.c\
			ft_putstr_pf.c\
			ft_putvoid_pf.c\
			ft_hexaupper_pf.c\
			ft_putdecimal_pf.c\
			ft_putunint_pf.c\
			get_next_line.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)
clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)
fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re

