# Name of the program
NAME	= libft.a

# Compiling flags
AR		= ar rcs
CC		= gcc
RL		= ranlib
FLAGS	= -Wall -Wextra -Werror -g

# Directories
SRC_DIR	= src
OBJ_DIR	= obj
INC_DIR	= inc

# Path of Directories
SRCS	= $(wildcard $(SRC_DIR)/*.c)
OBJS	= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compile
all:	obj
		@$(MAKE) -j $(NAME)

# Creates objs directory
obj:
	@mkdir -p $(OBJ_DIR)

# Compiling
$(NAME): $(OBJS)
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compiling... Aguanta"
	@$(AR) $(NAME) $(OBJS)
	@echo "(•̀ᴗ•́)و libft Kewl!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC_DIR)

# clean rule
clean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@echo "¯\_(ツ)_/¯ Objects ded!"

# fclean rule
fclean:	clean
	@rm -f $(NAME)
	@echo "(╯°□°）╯︵ ┻━┻ libft ded!"

# re rule
re:		fclean all

# phony
.PHONY: all clean fclean re
