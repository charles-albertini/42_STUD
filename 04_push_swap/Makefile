NAME = push_swap
HEADER = push_swap.h

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources et objets
SRCS = ./lst/ft_aff_lst.c\
		./arg/ft_atoi.c\
		./arg/ft_findarg.c\
		./arg/ft_getarg_str.c\
		./arg/ft_getarg.c\
		./sort/ft_issort.c\
		./lst/ft_lstadd_back.c\
		./lst/ft_lstadd_front.c\
		./lst/ft_lstdellast.c\
		./lst/ft_lstdelone.c\
		./lst/ft_lstlast.c\
		./lst/ft_lstnew.c\
		./lst/ft_lstnull.c\
		./lst/ft_lstsize.c\
		./lst/ft_free_stack.c\
		./arg/ft_only_int.c\
		./move/ft_pa.c\
		./move/ft_pb.c\
		./move/ft_ra.c\
		./move/ft_rb.c\
		./move/ft_rr.c\
		./move/ft_rra.c\
		./move/ft_rrb.c\
		./move/ft_rrr.c\
		./move/ft_sa.c\
		./move/ft_sb.c\
		./sort/ft_sort.c\
		./sort/ft_sort2.c\
		./sort/ft_sort3.c\
		./sort/ft_sort4.c\
		./sort/ft_sort5.c\
		./move/ft_ss.c\
		./move/ft_do_pbrb.c\
		./arg/ft_strlen.c\
		push_swap.c\
		pushswap.c\
		utils.c\
		utils2.c
OBJS = $(SRCS:.c=.o)

# Cible principale : créer la bibliothèque
all: $(NAME)

# Création de la bibliothèque à partir des fichiers objets
$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

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
