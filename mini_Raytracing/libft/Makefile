# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 17:16:37 by mda-silv          #+#    #+#              #
#    Updated: 2021/02/22 13:59:24 by mda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

LIB		= libft.h

CFLAGS	= -Wall -Wextra -Werror

CC 		= gcc

AR 		= ar -rcs

RM 		= rm -f

BONUS	= $(wildcard *lst*.c)

SRCS	= $(filter-out $(BONUS), $(wildcard *.c))
OBJS	= $(SRCS:.c=.o)
OBONUS	= $(BONUS:.c=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $@ $^

bonus: 		$(OBONUS) $(OBJS)
			$(AR) $(NAME) $^

%.o: %.c 	$(LIB)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(OBONUS)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all