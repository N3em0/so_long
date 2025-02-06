# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:58:15 by egache            #+#    #+#              #
#    Updated: 2025/02/06 21:48:18 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS		:=	mlx gnl ft m
LIBS_TARGET	:=				\
	mlx_linux/libmlx.a		\
	get_next_line/libgnl.a	\
	libft/libft.a			\

HEAD		:=				\
include						\
mlx_linux					\
get_next_line/include		\
libft						\

NAME	:=	so_long

SRC_DIR	:=	src
SRC		:=					\
so_long.c 					\
parsing.c					\

SRC		:=	$(SRC:%=$(SRC_DIR)/%)

BUILD_DIR:=	.build
OBJ		:=	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP		:=	$(OBJ:%.o=.d)

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror -g3
INCLUDE	:=	$(addprefix -I,$(HEAD)) -MMD -MP
LIBDIR	:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LIBNAME	:=	$(addprefix -l,$(LIBS))

AR	:=	ar -rcs

MAKEFLAGS	+=	--silent --no-print-directory

DIR_DUP	=	mkdir -p $(@D)

RM	:=	rm -f
RMF	:=	rm -rf

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(LIBS_TARGET)
			$(CC) $(LIBDIR) $(OBJ) $(LIBNAME) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			$(info CREATED CACA $(NAME))

$(LIBS_TARGET)	:
			@$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(info INCLUDE paths: $(INCLUDE)) $(INCLUDE) -O3 -c -o $@ $<
			$(info CREATED PIPI $@)

-include $(DEP)

clean:
			$(RM) $(OBJ) $(DEP)
			$(RMF) $(BUILD_DIR)
			$(MAKE) clean -C get_next_line
			$(MAKE) clean -C libft
			$(MAKE) clean -s -C mlx_linux

fclean:	clean
			$(RM) $(NAME)
			$(MAKE) fclean -C get_next_line
			$(MAKE) fclean -C libft
			$(MAKE) clean -s -C mlx_linux
			$(info CLEANED $(NAME))

re:
			$(MAKE) fclean
			$(MAKE) all

.PHONY:	all clean fclean re

.SILENT:
