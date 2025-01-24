# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:58:15 by egache            #+#    #+#              #
#    Updated: 2025/01/24 17:33:28 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD	=	include/so_long.h

MLX_HEAD=	minilibx-linux/mlx.h

NAME	=	so_long

SRCS_DIR=	src/

SRCS	=	so_long.c\

OBJS	=	${SRCS:%.c=${OBJS_DIR}%.o}

OBJS_DIR=	objs/

MLX		=	minilibx-linux/libmlx.a

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all			:	${NAME}

${OBJS_DIR}	:
			mkdir -p ${OBJS_DIR}

${OBJS} 	:   ${OBJS_DIR}%.o : ${SRCS_DIR}%.c ${HEAD} ${MLX_HEAD} Makefile
			${CC} ${FLAGS} -Iinclude -Imlx_linux -O3 -c $< -o $@

${NAME}		:	${OBJS_DIR} ${OBJS} ${HEAD}
			${CC} ${OBJS} ${MLX} -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

clean		:
			rm -rf ${OBJS}

fclean		:	clean
			rm -f ${NAME}

re			:	fclean all

.PHONY		:	all clean fclean re
