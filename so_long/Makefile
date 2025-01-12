NAME    := so_long
CFLAGS  := -Wextra -Wall -Werror -g
LIBMLX  := MLX42
MLX		:= MLX42
CLONE	:= git clone --depth=1

HEADERS := -I ./include -I $(LIBMLX)/include
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS    := $(shell find ./src ./libft ./printf ./gnl -iname "*.c")
OBJ_DIR := obj
OBJS    := $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(MLX) $(NAME)

$(MLX):
	$(CLONE) https://github.com/codam-coding-college/MLX42.git $(MLX)
	@cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(MLX)

re: fclean all

.PHONY: all clean fclean re



