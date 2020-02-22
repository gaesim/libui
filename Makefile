## Name of Project

NAME = libui.a

## Colors for shell

S_PRE = \0033[
S_POST = m
S_RESET = \0033[0m
S_ALIGN = \0033[30G
COLOR_DEFAULT = 39
COLOR_BLACK = 30
COLOR_RED = 31
COLOR_GREEN = 32
COLOR_YELLOW = 33
COLOR_BLUE = 34
COLOR_MAGENTA = 35
COLOR_CYAN = 36
COLOR_LIGHT_GRAY = 37
COLOR_DARK_GRAY = 90
COLOR_LIGHT_RED = 91
COLOR_LIGHT_GREEN = 92
COLOR_LIGHT_YELLOW = 93
COLOR_LIGHT_BLUE = 94
COLOR_LIGHT_MAGENTA = 95
COLOR_LIGHT_CYAN = 96
COLOR_WHITE = 97

BACKGROUND_DEFAULT = 49
BACKGROUND_BLACK = 40
BACKGROUND_RED = 41
BACKGROUND_GREEN = 42
BACKGROUND_YELLOW = 43
BACKGROUND_BLUE = 44
BACKGROUND_MAGENTA = 45
BACKGROUND_CYAN = 46
BACKGROUND_LIGHT_GRAY = 47
BACKGROUND_DARK_GRAY = 100
BACKGROUND_LIGHT_RED = 101
BACKGROUND_LIGHT_GREEN = 102
BACKGROUND_LIGHT_YELLOW = 103
BACKGROUND_LIGHT_BLUE = 104
BACKGROUND_LIGHT_MAGENTA = 105
BACKGROUND_LIGHT_CYAN = 106
BACKGROUND_WHITE = 107

COLOR_MESSAGE = $(S_PRE)$(COLOR_BLUE);$(BACKGROUND_DEFAULT)$(S_POST)
COLOR_TARGET = $(S_PRE)$(COLOR_CYAN);$(BACKGROUND_DEFAULT)$(S_POST)
TARGET = $(COLOR_TARGET)$(S_ALIGN)
COLOR_PROGRESS = $(S_PRE)$(COLOR_BLUE);$(BACKGROUND_GREEN)$(S_POST)
DEFAULT_PROGRESS = $(S_PRE)$(COLOR_RED);$(BACKGROUND_DARK_GRAY)$(S_POST)

## List of Directories

INC_DIR = inc
OBJ_DIR = obj
SRC_DIR = src
FRMWK_DIR = frmwrk

INIT_DIR = init
ERROR_DIR = error


## Compilating Utilities

# FAST = -Ofast
# DEBUG = -g3 -fsanitize=address
FLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -D_REENTRANT

INC = $(INC_DIR:%=-I ./%)
INC_FRMWK = -D_THREAD_SAFE -F ./$(FRMWK_DIR)

HOME =  $(shell pwd)/$(FRMWK_DIR)
FRMWK = -framework SDL2 -framework SDL2_image -framework SDL2_ttf -F ./$(FRMWK_DIR) -rpath $(HOME)

CC = clang $(FLAGS) $(INC)


## Test compilation differente


FRAMEWORKS = -framework SDL2 -framework SDL2_image -framework SDL2_ttf -F ./$(FRMWK_DIR) -rpath $(HOME)
LIBRARIES =


INC_FRAMEWORKS = -F ./$(FRMWK_DIR)

# FAST = -Ofast
# DEBUG = -g3 -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror $(FAST) $(DEBUG) -D_REENTRANT -D_THREAD_SAFE

# LDFLAGS = $(LIBRARIES) $(FRAMEWORKS)

# CC = clang $(CFLAGS) $(INC)
# EXEC =

## fin de test


## List of Functions

INCLUDE_H = libui

INIT_FT = ui_init

ERROR_FT = ui_error \
			ui_exit \
			ui_log_category

## List of Utilities

SRC = $(INIT_FT:%=$(SRC_DIR)/$(INIT_DIR)/%.c) \
		$(ERROR_FT:%=$(SRC_DIR)/$(ERROR_DIR)/%.c)

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(INIT_DIR:%=$(OBJ_DIR)/%) \
			$(ERROR_DIR:%=$(OBJ_DIR)/%)


INCLUDES = $(INCLUDE_H:%=./$(INC_DIR)/%.h)

## Progress bar

DONE_BAR = $(foreach i, $(filter $(shell cat log_objects), $(OBJ)),\0033[1D+)
STILL_BAR = $(foreach i, $(filter-out $(shell cat log_objects), $(OBJ)),\0033[1D-)
BAR = $(COLOR_PROGRESS)$(DONE_BAR)$(DEFAULT_PROGRESS)$(STILL_BAR)$(S_RESET)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR_MESSAGE)Libft$(TARGET)[All OK]$(S_RESET)"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR_MESSAGE)Creating$(TARGET)$@$(S_RESET)"

$(SRC):

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(INC_FRMWK) -c $< -o $@
	@echo "$(@)" >> log_objects
	@echo "\0033[1A$(BAR)"

$(NAME): $(OBJ_DIRS) $(SRC) $(INCLUDES) $(FRMWK_DIR)
	@touch log_objects
	@echo "Creating objects ...\n"
	@$(MAKE) -j --silent $(OBJ)
	@$(MAKE) bar --silent
	@echo "$(COLOR_MESSAGE)Objects$(TARGET)[Created]$(S_RESET)"
	@ar rcs $@ $(OBJ) 
	@echo "$(COLOR_MESSAGE)$(NAME)$(TARGET)[Created]$(S_RESET)"

clean:
	@rm -rf log_objects
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR_MESSAGE)Objects$(TARGET)[Deleted]$(S_RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR_MESSAGE)$(NAME)$(TARGET)[Deleted]$(S_RESET)"

aclean: fclean
	@rm -rf ./$(FRMWK_DIR)

re: fclean all

are: aclean all

norme:
	@norminette $(SRC) $(INC_DIR)/

bar:
	@echo "\0033[1A$(BAR)"

$(FRMWK_DIR):
	@mkdir ./$(FRMWK_DIR)
	@$(MAKE) -j --silent frameworks

frameworks:
	curl -o SDL2 https://www.libsdl.org/release/SDL2-2.0.8.dmg
	curl -o SDL2_image https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.3.dmg
	curl -o SDL2_ttf https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.dmg
	hdiutil attach SDL2
	hdiutil attach SDL2_image
	hdiutil attach SDL2_ttf
	cp -rf /Volumes/SDL2/SDL2.framework ./$(FRMWK_DIR)
	cp -rf /Volumes/SDL2_image/SDL2_image.framework ./$(FRMWK_DIR)
	cp -rf /Volumes/SDL2_ttf/SDL2_ttf.framework ./$(FRMWK_DIR)
	hdiutil detach /Volumes/SDL2
	hdiutil detach /Volumes/SDL2_image
	hdiutil detach /Volumes/SDL2_ttf
	rm -rf SDL2
	rm -rf SDL2_image
	rm -rf SDL2_ttf

.PHONY: all clean fclean re are norme bar frameworks
