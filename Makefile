# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alex <alex@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 05:57:11 by alex              #+#    #+#              #
#    Updated: 2025/04/01 17:08:37 by alex             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol_a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
LINK_FLAGS = -L$(INCLUDE_FILE)/libft -lft -L$(INCLUDE_FILE)/Minilibx -lmlx_Linux \
			-lXext -lX11 -lm -lz
	
# -L$(INCLUDE_FILE)/ft_printf -lftprintf
FILE_NAME = fractol
SRC_FILE = Src
HEADERS = $(SRC_FILE)/fractol.h
INCLUDE_FILE = include
SRC = $(SRC_FILE)/main.c $(SRC_FILE)/math_utils.c $(SRC_FILE)/utils.c \
		$(SRC_FILE)/set_definition.c $(SRC_FILE)/render.c \
		$(SRC_FILE)/create_cgi_env.c $(SRC_FILE)/events.c \
		$(SRC_FILE)/color_treatment.c

LIBFT = libft.a
MINI_LIBX = libmlx.a
PRINTF = libftprintf.a

OBJS = $(SRC:.c=.o)

all: $(LIBFT) $(MINI_LIBX) $(NAME) #$(PRINTF)

libft: $(LIBFT)

printf: $(PRINTF)

MiniLibx: $(MINI_LIBX)

message: 
	@echo "    _    _     ____    _    ____  ____  ___ _     "
	@echo "   / \\  | |   / ___|  / \\  |  _ \\|  _ \\|_ _| |    "
	@echo "  / _ \\ | |  | |     / _ \\ | |_) | |_) || || |    "
	@echo " / ___ \\| |__| |___ / ___ \\|  _ <|  _ < | || |___ "
	@echo "/_/   \\_\\_____\\____/_/   \\_\\_| \\_\\_| \\_\\___|_____|"
	@echo " La carpeta predefinida es: $(FILE_NAME). Si quieres cambiarla pon el nombre de la carpeta que contiene al proyecto EJ: make FILE_NAME="nombre de tu carpeta" "

$(LIBFT): 
	make all -C $(INCLUDE_FILE)/libft

# $(PRINTF):
# 	make all -C $(INCLUDE_FILE)/ft_printf

$(MINI_LIBX):
	make all -C $(INCLUDE_FILE)/Minilibx

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LINK_FLAGS) -I$(SRC_FILE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(INCLUDE_FILE)/libft
	make clean -C $(INCLUDE_FILE)/Minilibx
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f $(NAME)
	
fclean: clean
	make fclean -C $(INCLUDE_FILE)/libft
	make fclean -C $(INCLUDE_FILE)/Minilibx
	rm -f $(NAME)

re: fclean all

PHONY: make clean fclean re bonus
	

