SRC = strlen.c strchr.c toupper.c tolower.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

NAME = libft.a 
CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror 

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

DEP_DIR = deps
DEBUG ?= 0
RED := \033[1;31m
RESET := \033[0m

define debug_warning
$(warning $(RED)========================================$(RESET))
$(warning $(RED)=====!!! DEBUG FLAGS ARE ACTIVE !!!===== $(RESET))
$(warning $(RED)========================================$(RESET))
endef

ifeq ($(DEBUG),1)
CFLAGS += -g
$(eval $(call debug_warning))
endif
ifeq ($(DEBUG),2)
CFLAGS += -g -fsanitize=address -Wconversion -Wsign-conversion -fsanitize=undefined
$(eval $(call debug_warning))
endif

all: $(NAME)

$(NAME): $(OBJS)
	@LD_LIBRARY_PATH="" $(AR) -o $(NAME) $(OBJS)
	@echo "$(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@mkdir -p $(DEP_DIR)/$(dir $*)
	@$(CC) $(CFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@echo "cleaned objects.!."

fclean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@rm -f $(NAME)
	@echo "cleaned all.!."

urmom:
	make fclean
	@LD_LIBRARY_PATH="" compiledb -n make

re: fclean all

.PHONY: all clean fclean re urmom
