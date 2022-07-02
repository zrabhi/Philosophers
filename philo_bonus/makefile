#######colors#######
RED   := \033[0;31m
WHITE := \033[0;37m
GREEN := \033[0;32m
BLUE  := \033[0;34m
#####################

philo    = philo_bonus
draw     =  draw
SRC_DIR  = src
PARSING_DIR = $(SRC_DIR)/parsing
SRC		 = $(SRC_DIR)/ft_atoi.c $(PARSING_DIR)/ft_philo_utilis.c $(PARSING_DIR)/ft_isdigit.c $(PARSING_DIR)/ft_colors.c $(PARSING_DIR)/ft_check_input.c $(SRC_DIR)/ft_creat_lst.c $(SRC_DIR)/ft_create.c $(SRC_DIR)/philo_routine.c $(SRC_DIR)/philosopher_state.c $(SRC_DIR)/ft_philo_utilis.c
main	 = $(SRC_DIR)/main.c
OBJ		 = $(SRC:.c=.o)
CC		 = cc
GCCFLAGS = -Wall -Wextra -Werror -pthread 
HEADER   = $(SRC_DIR)/philosophers.h
NAME     = philo_bonus
PH := "\n$(GREEN)  _____  _     _ _____         _____  _______  _____   _____  _     _ _______  ______ _______\n |_____] |_____|   |   |      |     | |______ |     | |_____] |_____| |______ |_____/ |______\n |       |     | __|__ |_____ |_____| ______| |_____| |       |     | |______ |    \_ ______|\n                                                                                             \n$                       \n$(WHITE)\n"

all : $(NAME)
	@echo""
	@cat $(draw)/ascii-art.ans
	@cat $(draw)/philosophers-art.ans
	@echo""
	@echo "                  				$(BLUE)By zrabhi$(BLUE)                            "

$(NAME) : $(OBJ) $(main) $(HEADER)
	@$(CC) $(GCCFLAGS) $(main) $(OBJ) -o $(NAME)
	@echo""
	@sleep 0.2
	@echo "     $(GREEN)Compiling..........$(GREEN)"
	@sleep 0.2
	@echo ""
%.o: %.c	
		@$(CC) $(GCCFLAGS) -c $^ -o $@          

clean :
	@rm -rf $(OBJ)
	@echo "     $(GREEN)Removing object files..........$(GREEN)"
fclean : clean
	@rm -rf $(NAME)

re: fclean all
	@echo "     $(GREEN)Recompiling..........$(GREEN)"
