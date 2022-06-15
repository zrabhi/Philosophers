#######colors#######
RED   := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
BLUE  := \033[0;34m
#####################

philo    = philosophers
draw     =  draw
SRC_DIR  = src
SRC		 = $(SRC_DIR)/ft_atoi.c $(SRC_DIR)/ft_philo_utilis.c
main	 = $(SRC_DIR)/main.c
OBJ		 = $(SRC:.c=.o)
CC		 = gcc
GCCFLAGS = -Wall -Wextra -Werror
HEADER   = $(SRC_DIR)/philosophers.h
NAME     = philosophers
PH := "\n$(GREEN)  _____  _     _ _____         _____  _______  _____   _____  _     _ _______  ______ _______\n |_____] |_____|   |   |      |     | |______ |     | |_____] |_____| |______ |_____/ |______\n |       |     | __|__ |_____ |_____| ______| |_____| |       |     | |______ |    \_ ______|\n                                                                                             \n$                       \n$(WHITE)\n"

all : $(NAME)
	@cat $(draw)/ascii-art.ans
	@echo $(PH)
$(NAME) : $(OBJ) $(main) $(HEADER)
	@$(CC) $(GCC_FLAGS) $(main) $(OBJ) -o $(NAME)
	@echo""
	@sleep 0.2
	@echo "     $(GREEN)Compiling..........$(GREEN)"
	@sleep 0.2
	@echo ""
%.o: %.c	
		@$(CC) $(GCC_FLAGS) -c $^ -o $@          

clean :
	@rm -rf $(OBJ)
	@echo "     $(GREEN)Removing object files..........$(GREEN)"
fclean : clean
	@rm -rf $(NAME)

re: fclean all
	@echo "     $(GREEN)Recompiling..........$(GREEN)"




