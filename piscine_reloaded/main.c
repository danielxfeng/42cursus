#include <stdio.h>

//#include "./ex06/ft_print_alphabet.c"
//#include "./ex07/ft_print_numbers.c"
//#include "./ex08/ft_is_negative.c"
#include "./ex09/ft_ft.c"
#include "./ex10/ft_swap.c"
#include "./ex11/ft_div_mod.c"
#include "./ex12/ft_iterative_factorial.c"
#include "./ex13/ft_recursive_factorial.c"
#include "./ex14/ft_sqrt.c"


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
	// ex11
	int a11 = 5;
	int b11 = 2;
	int c11;
	int d11;
	ft_div_mod(a11, b11, &c11, &d11);
	printf("%d, %d\n", c11, d11);
	// ex12
	int nb12 = 10;
	printf("%d\n", ft_iterative_factorial(nb12)); // 3628800
	// ex13
	int nb13 = 10;
	printf("%d\n", ft_recursive_factorial(nb13));
	// ex14
	int nb = 10000;
	printf("%d\n", ft_sqrt(nb));
	nb = 100001;
	printf("%d\n", ft_sqrt(nb));
}
