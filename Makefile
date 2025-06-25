# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tvan-tui <tvan-tui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 14:52:01 by tvan-tui          #+#    #+#              #
#    Updated: 2025/05/07 13:48:27 by tvan-tui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = obj
INCLUDES_DIR = includes

SRCS = \
	$(SRCS_DIR)/big_sort.c \
	$(SRCS_DIR)/errors.c \
	$(SRCS_DIR)/free.c \
	$(SRCS_DIR)/init_nodes_a.c \
	$(SRCS_DIR)/init_nodes_b.c \
	$(SRCS_DIR)/initialize.c \
	$(SRCS_DIR)/main.c \
	$(SRCS_DIR)/moves.c \
	$(SRCS_DIR)/operations.c \
	$(SRCS_DIR)/push_instructions.c \
	$(SRCS_DIR)/revrotate_instructions.c \
	$(SRCS_DIR)/rotate_instructions.c \
	$(SRCS_DIR)/rotate.c \
	$(SRCS_DIR)/sort.c \
	$(SRCS_DIR)/stack.c \
	$(SRCS_DIR)/swap_instructions.c \
	$(SRCS_DIR)/utils.c

OBJS = \
	$(OBJS_DIR)/big_sort.o \
	$(OBJS_DIR)/errors.o \
	$(OBJS_DIR)/free.o \
	$(OBJS_DIR)/init_nodes_a.o \
	$(OBJS_DIR)/init_nodes_b.o \
	$(OBJS_DIR)/initialize.o \
	$(OBJS_DIR)/main.o \
	$(OBJS_DIR)/moves.o \
	$(OBJS_DIR)/operations.o \
	$(OBJS_DIR)/push_instructions.o \
	$(OBJS_DIR)/revrotate_instructions.o \
	$(OBJS_DIR)/rotate_instructions.o \
	$(OBJS_DIR)/rotate.o \
	$(OBJS_DIR)/sort.o \
	$(OBJS_DIR)/stack.o \
	$(OBJS_DIR)/swap_instructions.o \
	$(OBJS_DIR)/utils.o

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB) | $(OBJS_DIR)
	$(CC) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
