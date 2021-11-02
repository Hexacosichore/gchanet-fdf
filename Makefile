# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 07:37:56 by gchanet           #+#    #+#              #
#    Updated: 2021/10/21 11:05:23 by gchanet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU 		= \033[0;34m
GRN 		= \033[0;32m
RED 		= \033[0;31m
RST 		= \033[0m

SRCS		= main.c \
				hook.c \
				render.c \
				parser.c \
				utils.c \
				transform.c \
				interface.c
OBJS		= ${addprefix src/, ${SRCS:.c=.o}}
GCC			= gcc
GCC_FLAGS	= -Wall -Wextra -Werror -fsanitize=address -fdiagnostics-color 
LIBX 		= -L../libft/ -lft \
				-L../lib3d/ -l3d  \
				-L../minilibx-linux -lmlx -Imlx \
				-lXext -lX11 -lz -lm
NAME		= fdf

all: ${NAME}

.c.o:
	@${GCC}  -c $< -o ${<:.c=.o}
	@echo "${BLU}[BUILD]${RST} ${<:.c=.o}"

${NAME}: ${OBJS}
	@${GCC} -o ${NAME} ${OBJS} ${LIBX} 
	@echo "${GRN}[DONE]${RST} ${NAME} has created"

clean:
	@rm -f *.o
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@rm -f ${NAME}
	@echo "${GRN}[FCLEAN]${RST} done"

run: re
	@echo "${BLU}[RUN]${RST}"
	@./${NAME}

re: fclean all