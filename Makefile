# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: merel <merel@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 09:38:13 by cpost             #+#    #+#              #
#    Updated: 2022/12/19 10:53:09 by merel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========= General variables =========#
#=====================================#

SRC_PATH = src
OBJ_PATH = obj
INC_PATH = include lib/Libft/include lib/get_next_line/include lib/MLX42/include

LIBFT_PATH = lib/Libft/
GNL_PATH = lib/get_next_line/
MLX42_PATH = lib/MLX42/

NAME = cub3D

BOLD = \033[1m
GREEN = \033[32;1m
RED	= \033[31;1m
YELLOW	= \033[33;1m
RESET = \033[0m

#=====================================#
#========= Command arguments =========#
#=====================================#

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
#MLXFLAGS = -I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
MLXFLAGS = -lglfw -L/opt/homebrew/Cellar/glfw/3.3.8/lib/#Not at codam

#=====================================#
#============ Input files ============#
#=====================================#

SRC = $(shell find $(SRC_PATH) -type f -name '*.c')

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIBFT_PATH)libft.a $(GNL_PATH)getnextline.a
LIB += $(MLX42_PATH)libmlx42.a

#=====================================#
#=============== Rules ===============#
#=====================================#

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(GNL_PATH)
	@make -C $(MLX42_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(MLXFLAGS) $(OBJ) $(INC) -o $(NAME) && printf "$(YELLOW)$(BOLD)\rBuild $(NAME)\r\e[35C[OK]\n$(RESET)"

$(OBJ_PATH)/%.o: %.c include/cub3d*
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

run: all
	@./cub3D

cleanlib:
	@make -C $(LIBFT_PATH) clean
	@make -C $(GNL_PATH) clean

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)Cleaning cub3D$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(GNL_PATH) fclean
	@make -C $(MLX42_PATH) fclean

re: fclean all

play: all
	./cub3D maps/subject.cub

.PHONY: clean, fclean, re, all, play
