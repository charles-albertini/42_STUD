NAME = so_long
HEADER = so_long.h

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources et objets
SRCS = main.c

OBJS = $(SRCS:.c=.o)

# Cible principale : créer la bibliothèque
all: $(NAME)

# Création de la bibliothèque à partir des fichiers objets
$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) MLX42/libmlx42.a -IMLX42/include -ldl -lglfw -pthread -lm -o $(NAME)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJS)

# Nettoyage complet (fichiers objets et bibliothèque)
fclean: clean
	rm -f $(NAME)

# Récompilation complète
re: fclean all

# ar s creer un index pour que le programme retrouve plus facilement les fonctions 
# ar r ajoute les fichiers objet dans l'archive 
# ar c creer l'archive si elle n'existe pas
# ar ... name obj, on creer la bibliotheque NAME en mettant les OBJ dedans 
# cc -c, le -c (compile only), compile uniquement pour avor un fichier o a partir d'un fichier c sans creer d'executable 
# le % represente n'importe quel nom de fichier

.PHONY: all clean fclean re
