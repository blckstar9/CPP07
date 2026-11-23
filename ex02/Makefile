# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 14:58:00 by aybelaou          #+#    #+#              #
#    Updated: 2026/04/21 14:58:00 by aybelaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -----------------------------------Colors------------------------------------

ORANGE				= \033[38;2;255;165;0m
BOLD_ORANGE		= \033[1;38;5;214m
BG_YELLOW			= \033[48;5;214m
MAGENTA				= \033[0;35m
BOLD_MAGENTA		= \033[1;35m
RESET				= \033[0m

# ---------------------------------Compilation---------------------------------

NAME				= ex02
CPP					= c++
CPPFLAGS			= -Wall -Wextra -Werror -std=c++98
LDFLAGS				=
RM					= rm -rf

OBJ_DIR				= obj
SRC					= main.cpp
OBJ					= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

# -----------------------------------Rules-------------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(ORANGE)Building $(NAME)...$(RESET)"
	@$(CPP) $(OBJ) $(CPPFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "$(BOLD_ORANGE)$(NAME) is ready!$(RESET)"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@echo "$(ORANGE)Compiling $<...$(RESET)"
	@$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(MAGENTA)Cleaning object files...$(RESET)"
	@$(RM) -r $(OBJ_DIR)
	@echo "$(BOLD_MAGENTA)All object files cleaned!$(RESET)"

fclean: clean
	@echo "$(MAGENTA)Removing the executable...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(BOLD_MAGENTA)Executable removed!$(RESET)"

re: fclean all
	@echo "$(BG_YELLOW)Cleaned and rebuilt everything!$(RESET)"

.PHONY: all clean fclean re
