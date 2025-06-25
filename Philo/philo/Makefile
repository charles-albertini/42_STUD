NAME    := philo
CFLAGS  := -Wextra -Wall -Werror -pthread -g

SRCS    := $(shell find ./src -iname "*.c")
OBJ_DIR := obj
OBJS    := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
