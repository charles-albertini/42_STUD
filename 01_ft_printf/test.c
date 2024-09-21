#include <stdio.h>
#include "libftprintf.h"

int	main(void)
{
	char c = 'D';
	int nb = 42;
	int nb2 = 45;
	char *str = "salut";
	int *ptr = &nb;
	unsigned int ui= 123456;
	int hex = 1234;
	
	ft_printf("Mine : %c %d %d\n", c, nb, nb2);
	printf("Real : %c %d %d\n", c, nb, nb2);
    
	ft_printf("Mine : %s \n", str);
	printf("Real : %s \n", str);
    
	ft_printf("Mine : %p \n", ptr);
	printf("Real : %p \n", ptr);
    
	ft_printf("Mine : %d %d \n", nb, nb2);
	printf("Real : %d \n", nb);
    
	ft_printf("Mine : %i \n", nb);
	printf("Real : %i \n", nb);
    
	ft_printf("Mine : %u \n", ui);
	printf("Real : %u \n", ui);
    
	ft_printf("Mine : %x \n", hex);
	printf("Real : %x \n", hex);
    
	ft_printf("Mine : %X \n", hex);
	printf("Real : %X \n", hex);
    
	ft_printf("Mine : %% \n");
	printf("Real : %% \n");

	
	return (0);
}

