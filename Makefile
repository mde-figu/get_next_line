# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-figu <mde-figu@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 11:47:38 by mde-figu          #+#    #+#              #
#    Updated: 2021/07/16 11:49:00 by mde-figu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= $(shell find "." -name "*.c")
OBJS		= ${SRCS:.c=.o}
NAME		= get_next_line.a
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror
AR			= ar csr

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	${AR} get_next_line.a ${OBJS}


all : ${NAME}

clean :
	${RM} ${OBJS} 

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re .c.o
