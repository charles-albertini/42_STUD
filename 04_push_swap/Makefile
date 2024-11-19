NAME = libftprintf.a

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources et objets
SRCS = ft_printf.c	\
		ft_isformat.c	\
		ft_format.c	\
		ft_putchar.c	\
		ft_putstr.c	\
		ft_putnbr.c	\
		ft_putnbrui.c	\
		ft_hexa.c	\
		ft_ptr.c	\
		ft_strlen.c
OBJS = $(SRCS:.c=.o)

# Cible principale : créer la bibliothèque
all: $(NAME)

# Création de la bibliothèque à partir des fichiers objets
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compilation des fichiers objets
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet (fichiers objets et bibliothèque)
fclean: clean
	rm -f $(NAME)

# Récompilation complète
re: fclean all

.PHONY: all clean fclean re
