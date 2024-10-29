NAME = libft.a

SRC = ft_atoi.c	\
		#ft_bzero.c	\
		#ft_calloc.c	\
		#ft_isalnum.c	\
		#ft_isalpha.c	\
		#ft_isascii.c	\
		#ft_isdigit.c	\
		#ft_isprint.c	\
		#ft_itoa.c	\
		#ft_memchr.c	\
		#ft_memcmp.c	\
		#ft_memcpy.c	\
		ft_memmove.c	
		#ft_memset.c	\
		#ft_putchar_fd.c	\
		#ft_putendl_fd.c	\
		#ft_putnbr_fd.c	\
		#ft_putstr_fd.c	\
		#ft_split.c	\
		#ft_strchr.c	\
		#ft_strdup.c	\
		#ft_striteri.c	\
		#ft_strjoin.c	\
		#ft_strlcat.c	\
		#ft_strlcpy.c	\
		#ft_strlen.c	\
		#ft_strmapi.c	\
		#ft_strncmp.c	\
		#ft_strnstr.c	\
		#ft_strrchr.c	\
		#ft_strtrim.c	\
		#ft_substr.c	\
		#ft_tolower.c	\
		#ft_toupper.c
OBJ = $(SRC:.c=.o)

BONUS = #ft_lstnew_bonus.c	\
		#ft_lstadd_front_bonus.c	\
		#ft_lstsize_bonus.c	\
		#ft_lstlast_bonus.c	\
		#ft_lstadd_back_bonus.c	\
		#ft_lstdelone_bonus.c	\
		#ft_lstclear_bonus.c	\
		#ft_lstiter_bonus.c	\
		#ft_lstmap_bonus.c
BOBJ = $(BONUS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

bonus:	$(OBJ) $(BOBJ)
		ar rcs $(NAME) $(OBJ) $(BOBJ)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $^

clean :
		$(RM) $(OBJ) $(BOBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re

# ar s creer un index pour que le programme retrouve plus facilement les fonctions 
# ar r ajoute les fichiers objet dans l'archive 
# ar c creer l'archive si elle n'existe pas
# ar ... name obj, on creer la bibliotheque NAME en mettant les OBJ dedans 
# cc -c, le -c (compile only), compile uniquement pour avor un fichier o a partir d'un fichier c sans creer d'executable 
# le % represente n'importe quel nom de fichier
# on compile avec -o pour dire que le nom des fichier o sera le nom des fichier c
