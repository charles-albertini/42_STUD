NAME    := ClapTrap
CXX     := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98

SRCS    := $(shell find -iname "*.cpp")
OBJ_DIR := obj
OBJS    := $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
