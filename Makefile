# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cpost <cpost@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/12/05 09:38:13 by cpost         #+#    #+#                  #
#    Updated: 2022/12/05 13:26:43 by cpost         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#=====================================#
#========= General variables =========#
#=====================================#

SRC_PATH = src
OBJ_PATH = obj
INC_PATH = include lib/Libft/include lib/get_next_line/include

LIBFT_PATH = lib/Libft/
GNL_PATH = lib/get_next_line/

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

#=====================================#
#============ Input files ============#
#=====================================#

SRC = $(shell find $(SRC_PATH) -type f -name '*.c')

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

INC = $(addprefix -I,$(INC_PATH))
LIB = $(LIBFT_PATH)libft.a $(GNL_PATH)getnextline.a

#=====================================#
#=============== Rules ===============#
#=====================================#

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(GNL_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ) $(INC) -o $(NAME) && printf "$(YELLOW)$(BOLD)\rBuild $(NAME)\r\e[35C[OK]\n$(RESET)"

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

re: fclean all

.PHONY: clean, fclean, re, all