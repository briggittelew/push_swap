# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 12:38:22 by karlewis          #+#    #+#              #
#    Updated: 2024/02/07 12:38:26 by karlewis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
HDRS		:= push_swap.h

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

LFT_PATH	:= libft
LIBFT		:= $(LFT_PATH)/libft.a

SRCS_DIR	:= sources
HDRS_DIR	:= headers
vpath %.c	$(SRCS_DIR)
vpath %.h	$(HDRS_DIR)
INCLUDES	:= -I$(HDRS_DIR) -I$(LFT_PATH)

SRCS		:= error.c \
			check.c \
			split_and_align_a.c \
			filling_stack.c \
			list_functions.c \
			operations.c \
			utils.c \
			heapsort.c \
			asipes_algorithm.c \
			small_sorts.c \
			small_sorts_b.c \
			compress.c \
			main.c

OBJS_DIR	:= .objects
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all:				libft
					@echo "$(BOLD)Creating/updating '$(NAME)'...$(DEF)"
					@$(MAKE) --no-print-directory $(NAME)

$(NAME):			$(OBJS) $(LIBFT)
					@echo "$(BOLD)Linking files...$(DEF)"
					@$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) -o $@ $(LIBFT)
					@echo "$(BOLD)'$(NAME)' has been created/updated.$(DEF)"

$(OBJS_DIR)/%.o:	%.c $(HDRS) $(LIBFT) | $(OBJS_DIR)
					@echo "Assembling $<..."
					@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
					@mkdir -p $@
					@echo "$(BOLD)Directory '$(OBJS_DIR)' has been created.$(DEF)"

libft:
					@$(MAKE) --no-print-directory -C $(LFT_PATH)

clean:
					@$(MAKE) --no-print-directory clean -C $(LFT_PATH)
					@rm -rf $(OBJS)
					@echo "$(NAME): $(BOLD)Object files have been cleaned.$(DEF)"

fclean:				clean
					@rm -rf $(LIBFT)
					@echo "$(BOLD)'$(LIBFT)' has been cleaned.$(DEF)"
					@rm -rf $(NAME)
					@echo "$(BOLD)'$(NAME)' has been cleaned.$(DEF)"

re:					fclean all

.PHONY:				all clean fclean re libft

BOLD	:= \033[1m
DEF		:= \033[0;39m