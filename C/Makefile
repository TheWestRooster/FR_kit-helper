NAME = kit_helper

SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = include/

CLANG = cc
CC_FLAGS = -Wall -Werror -Wextra -g -I$(INC_DIR)

FILES =	main.c \
		init.c \
		items.c \
		stats.c \
		effects.c \
		linked_list.c
FILES_PATH = $(addprefix $(SRC_DIR), $(FILES))
OBJS = $(FILES:.c=.o)
OBJS_PATHS = $(patsubst %, $(OBJ_DIR)%, $(OBJS))

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	$(CLANG) $(CC_FLAGS) $< -c -o $@

$(NAME): $(OBJS_PATHS)
	$(CLANG) -o $(NAME) $(OBJS_PATHS) -lreadline

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(CLIENT_NAME)

all: $(NAME)

re: fclean all