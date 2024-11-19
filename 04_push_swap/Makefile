NAME = push_swap

# Compilateur et flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Fichiers sources et objets
SRCS = ft_aff_lst.c	\
		ft_atoi.c	\
		ft_findarg.c	\
		ft_getarg_str.c	\
		ft_getarg.c \
		ft_issort.c	\
		ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstdellast.c	\
		ft_lstdelone.c	\
		ft_lstlast.c   \
		ft_lstnew.c	\
		ft_lstnull.c	\
		ft_lstsize.c	\
		ft_new_pivot.c	\
		ft_only_int.c	\
		ft_pa.c	\
		ft_pb.c	\
		ft_pivot.c	\
		ft_ra.c	\
		ft_rb.c	\
		ft_rev_sort2.c   \
		ft_rev_sort3.c   \
		ft_rr.c   \
		ft_rra.c   \
		ft_rrb.c   \
		ft_rrr.c   \
		ft_sa.c   \
		ft_sb.c   \
		ft_sort_pivot.c   \
		ft_sort2.c   \
		ft_sort3.c   \
		ft_ss.c   \
		ft_strlen.c   \
		push_swap.c   
OBJS = $(SRCS:.c=.o)

# Cible principale : créer la bibliothèque
all: $(NAME)

# Création de la bibliothèque à partir des fichiers objets
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

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

.PHONY: all clean fclean re
