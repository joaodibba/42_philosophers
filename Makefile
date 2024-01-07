# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalves-c < jalves-c@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 18:24:09 by jalves-c          #+#    #+#              #
#    Updated: 2023/11/06 13:40:16 by jalves-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= @cc
FLAGS	= -I./include -Wall -Wextra -Werror -pthread -g -fsanitize=address 
OBJ  	= $(patsubst src/%.c, obj/%.o, $(SRC))
SRC		:=	src/core/main.c \
			src/core/validations.c \
			src/utils/utils.c \
			src/utils/error.c \
			src/setup/dinner_time.c \
			src/setup/setup_list.c \
			src/utils/clean.c \
			src/threads/philo.c \
			src/threads/routine.c \
			src/utils/time.c 

# COLORS
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
RESET   = \033[0m

all: obj $(NAME)

$(NAME): $(OBJ)
	@echo "[" "$(YELLOW)..$(RESET)" "] | Compiling $(NAME)..."
	$(CC) $(FLAGS) -o $@ $^
	@echo "[" "$(GREEN)OK$(RESET)" "] | $(NAME) ready!"

obj:
	@mkdir -p obj

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing object files...$(RESET)"
	@rm -rf $(OBJ) obj
	@echo "[" "$(GREEN)OK$(RESET)" "] | Object files removed."

fclean: clean
	@echo "[" "$(YELLOW)..$(RESET)" "] | Removing binary files...$(RESET)"
	@rm -rf $(NAME)
	@echo "[" "$(GREEN)OK$(RESET)" "] | Binary file removed."

norm:
	@echo "[" "$(YELLOW)..$(RESET)" "] | Running Norminette...$(RESET)"
	@if norminette src include/philo.h | grep -q "Error!"; then \
	    echo "[" "$(RED)!!$(RESET)" "] | Norminette found errors.$(RESET)"; \
	    norminette src include/philo.h | awk '/Error!/ {print "[ " "$(RED)!!$(RESET)" " ] | " $$0}'; \
	else \
	    echo "[" "$(GREEN)OK$(RESET)" "] | Norminette passed!"; \
	fi

re: fclean norm all
	@make -s

.PHONY: all