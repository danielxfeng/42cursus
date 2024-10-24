#include <stdio.h>

//#include "./ex06/ft_print_alphabet.c"
//#include "./ex07/ft_print_numbers.c"
//#include "./ex08/ft_is_negative.c"
#include "./ex09/ft_ft.c"
#include "./ex10/ft_swap.c"


int	main(void)
{
	// ex06
	//ft_print_alphabet();
	// ex07
	//ft_print_numbers();
	// ex08
	//ft_is_negative(9);
	//ft_is_negative(-1);
	//ft_is_negative(0);
	// ex09
	int nbr;
	ft_ft(&nbr);
	printf("%d\n", nbr);
	// ex10
	int a = 10;
	int b = 11;
	ft_swap(&a, &b);
	printf("%d, %d\n", a, b);
}
