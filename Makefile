# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almohame <almohame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 08:10:52 by almohame          #+#    #+#              #
#    Updated: 2024/05/18 14:23:28 by almohame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

FILES =  push_swap ft_atoi ft_split rotate reverse_rotate swap push utilles sort_stack radix helper\

PRINTF = ft_printf/libftprintf.a

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(PRINTF):
	make -C ft_printf

$(NAME): $(OBJS) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

clean:
	make clean -C ft_printf
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	make fclean -C ft_printf
	$(RM) $(NAME) $(PRINTF)

re: fclean all

.PHONY: all clean fclean re