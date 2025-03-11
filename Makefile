# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 15:58:15 by egache            #+#    #+#              #
#    Updated: 2025/03/11 21:52:28 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBS		:=	mlx gnl ft printf m
LIBS_TARGET	:=				\
	mlx_linux/libmlx.a		\
	get_next_line/libgnl.a	\
	libft/libft.a			\
	ft_printf/libprintf.a	\

HEADER := include/so_long.h

HEAD		:=				\
include						\
mlx_linux					\
get_next_line/include		\
libft/include				\
ft_printf/include			\

NAME	:=	so_long

SRC_DIR	:=	src
SRC		:=					\
so_long.c 					\
map_initialisation.c		\
map_check.c					\
display_image.c				\
movement.c					\
win_condition.c				\
hud.c						\
free_exit.c					\

SRC		:=	$(SRC:%=$(SRC_DIR)/%)

BUILD_DIR:=	.build
OBJ		:=	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP		:=	$(OBJ:%.o=.d)

AR	:=	ar -rcs

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
INCLUDE	:=	$(addprefix -I,$(HEAD)) -MMD -MP
LIBDIR	:=	$(addprefix -L,$(dir $(LIBS_TARGET)))
LIBNAME	:=	$(addprefix -l,$(LIBS))

DIR_DUP	=	mkdir -p $(@D)

MAKEFLAGS	+=	--no-print-directory

RM	:=	rm -f
RMF	:=	rm -rf

BOLDGREEN	:= \e[1;32m
BOLDBLUE 	:= \033[1;34m
YELLOW		:= \033[1;93m
WHITE 		:= \033[0m
BLUE		:= \033[0;34m
PURPLE		:= \e[1;35m

all	:	.printsep $(NAME)
		echo "$(BOLDBLUE)$(NAME) $(WHITE)compilation $(BOLDGREEN)done"
		$(call SEPARATOR)

$(NAME)	:	$(OBJ) $(LIBS_TARGET) $(HEADER)
			$(CC) $(LIBDIR) $(OBJ) $(LIBNAME) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
			$(call SEPARATOR)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)compilation  $(YELLOW)..."
			$(call SEPARATOR)

$(LIBS_TARGET)	: FORCE
			@$(MAKE) -C $(@D)
			@echo "$(BOLDBLUE)$(@D) $(WHITE)library $(BOLDGREEN)done"

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

-include $(DEP)

clean:
			$(RM) $(OBJ) $(DEP)
			$(RMF) $(BUILD_DIR)
			$(MAKE) clean -C get_next_line
			$(MAKE) clean -C libft
			$(MAKE) clean -C ft_printf
			$(MAKE) clean -s -C mlx_linux

fclean:	clean
			$(call SEPARATOR)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)fclean  $(YELLOW)..."
			$(RM) $(NAME)
			$(MAKE) fclean -C get_next_line
			$(MAKE) fclean -C libft
			$(MAKE) fclean -C ft_printf
			$(MAKE) clean -s -C mlx_linux
			$(call SEPARATOR)
			echo "$(BOLDBLUE)$(NAME) $(WHITE)fclean  $(BOLDGREEN)done"

re:
			$(MAKE) fclean
			$(MAKE) all


FORCE :

.PHONY:	all clean fclean FORCE re

.SILENT:

.printsep:
			$(call SEPARATOR)

define	SEPARATOR
						@echo "\n$(PURPLE)--------------------------$(WHITE)\n";
endef
