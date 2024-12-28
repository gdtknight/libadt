# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoshin <yoshin@student.42gyeongsan.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 18:16:41 by yoshin            #+#    #+#              #
#    Updated: 2024/12/28 14:04:59 by yoshin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile v1.0

NAME		=	libadt.a

CFLAGS		=	-Wall -Wextra -Werror
ARFLAGS		=	rcs

HEADER_DIR	=	includes
SRC_DIR		=	srcs

BUILD_DIR	=	build
BIN_DIR		=	bin

SRCS		:=	$(shell find ./$(SRC_DIR) -name '*.c')
OBJS		:=	$(SRCS:%=$(BUILD_DIR)/%.o)

ifeq ($(debug), 1)
	override CFLAGS	+=	-g
endif

.PHONY: all clean fclean re debug
all: $(NAME)

$(NAME): $(OBJS) | $(BIN_DIR)
	$(AR) $(ARFLAGS) $(BIN_DIR)/$@ $(OBJS)
	cp	$(BIN_DIR)/$@ ./$@

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADER_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)

fclean: clean
	rm -rf $(NAME) $(HEADERS).gch

re: fclean all

debug: fclean
	make debug=1
