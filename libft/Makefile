# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: karlewis <karlewis@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 12:36:56 by karlewis          #+#    #+#              #
#    Updated: 2024/02/07 12:37:12 by karlewis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a
HDRS		:= libft.h

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror		

SRCS_DIR	:= sources
HDRS_DIR	:= headers
vpath %.c	$(SRCS_DIR)
vpath %.h	$(HDRS_DIR)
INCLUDES	:= -I$(HDRS_DIR)

SRCS 		:= ft_putchar.c ft_putstr.c ft_strlen.c ft_putnbr.c ft_strcmp.c \
			ft_strncmp.c ft_swap.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
			ft_strlcpy.c ft_strlcat.c ft_bzero.c ft_memset.c ft_memcpy.c \
			ft_memmove.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_isalpha.c \
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
			ft_tolower.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_printclst.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstmap.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			get_next_line.c get_next_line_utils.c

OBJS_DIR	:= .objects
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all:
					@echo "$(BOLD)Creating/updating libft...$(DEF)"
					@$(MAKE) --no-print-directory $(NAME) -j 8

$(NAME):			$(OBJS)
					@echo "$(BOLD)Inserting files into library...$(DEF)"
					@ar rcs $(NAME) $?
					@echo "$(BOLD)Library has been created/updated.\n$(DEF)"

$(OBJS_DIR)/%.o:	%.c $(HDRS) | $(OBJS_DIR)
					@echo "Assembling $<..."
					@$(CC) $(FCLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
					@mkdir -p $@
					@echo "$(BOLD)Directory '$(OBJS_DIR)' has been created.$(DEF)"

clean:
					@rm -f $(OBJS)
					@echo "libft: $(BOLD)Object files have been cleaned.$(DEF)"

fclean:				clean
					@rm -f $(NAME)
					@echo "$(BOLD)'$(NAME)' has been cleaned.$(DEF)"

re: 				fclean all

.PHONY:				all clean fclean re

BOLD	:= \033[1m
DEF		:= \033[0;39m