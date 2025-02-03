# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpedrosa <rpedrosa@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 12:07:09 by rpedrosa          #+#    #+#              #
#    Updated: 2024/11/20 12:07:14 by rpedrosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###Files###

SRCS = handle_inputs.c so_long.c create_matrix.c check_map.c map_dim.c check_path.c \
			 ft_exit.c draw_map.c game_ini.c player_moves.c update.c

#BONUS_SRCS =

OBJS = $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS:.c=.o)))

#BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = so_long

MLX_PATH = minilibx-linux
LIBFT_PATH = libft
LIBFT_ARC = libft/libft.a
LIBFT_OBJS = libft/.build
BUILD_PATH = .build_so_long

LIB_NAME = so_long.a

###ALIAS###

RM = rm -rf
AR = ar rcs
CFLAGS = -g -Wall -Werror -Wextra
MAKEE = make -s extra

#OBJS_ALL = $(OBJS) $(BONUS_OBJS)

###Rules###

all: deps $(LIBFT_ARC) $(LIB_NAME) $(NAME)

$(BUILD_PATH):
	@mkdir $(BUILD_PATH)

$(NAME): $(LIB_NAME) $(OBJS) 
	@cc $(CFLAGS) $(LIBFT_ARC) $(LIB_NAME) -L$(MLX_PATH) -lmlx_Linux -Lusr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GRN)[so_long created, GLHF!]$(D)"

dominilibx: $(MLX_PATH)
	@echo "$(MAG)[Compiling minilibx ...]$(D)"
	@make -sC $(MLX_PATH)
	@echo "$(MAG)[Minilibx successfully compiled!]$(D)"

$(LIBFT_ARC): $(LIBFT_PATH)
	@$(MAKEE) -C $(LIBFT_PATH)

$(LIB_NAME): $(BUILD_PATH) $(MLX_ARC) $(OBJS)
	@$(AR) $(LIB_NAME) $(OBJS) $(LIBFT_OBJS)/*.o

$(BUILD_PATH)/%.o: %.c
	@cc $(CFLAGS) -I/usr/include -Iminilibx-linux -o $@ -c $<

deps:	## Download/Update libft
	@if test ! -d "$(LIBFT_PATH)"; then make -s get_libft; \
		else echo "$(GRN)[Libft folder found]$(D)"; fi
	@if test ! -d "$(MLX_PATH)"; then make -s get_minilibx; \
		else echo "$(MAG)[Minilibx folder found]$(D)"; fi
	@if test ! -d "$(MLX_PATH)/obj"; then make -s dominilibx; \
		else echo "$(GRN)[All folders found. No relink!]$(D)"; fi

get_libft:
	@echo "[$(CYA)Downloading Libft$(D)]"
	git clone git@github.com:rfpoliveira/42_Libft.git $(LIBFT_PATH)
	@echo "$(CYA)[Libft successfully downloaded]$(D)"

get_minilibx:
	@echo "[$(MAG)Downloading Minilibx$(D)]"
	git clone git@github.com:42Paris/minilibx-linux.git $(MLX_PATH)
	@echo "$(MAG)[Minilibx successfully downloaded]$(D)"

clean: 
	@$(RM) $(BUILD_PATH)
	@echo "$(BCYA)[clean] Objects removed$(D)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIB_NAME)
	@$(RM) $(LIBFT_PATH)
	@$(RM) $(MLX_PATH)
	@echo "$(BCYA)[fclean] Archive, Libft and Minilibx removed$(D)"

again: clean
	@echo "$(BCYA)[rebuilding...]$(D)"
	@$(RM) $(NAME)
	@$(RM) $(LIB_NAME)
	@$(MAKE) -s

re: fclean all

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'

B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
