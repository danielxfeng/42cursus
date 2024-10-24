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
#include "./ex15/ft_putstr.c"
#include "./ex16/ft_strlen.c"
#include "./ex17/ft_strcmp.c"

int	main(void)
{
	int	nbr;
	int	a;
	int	b;
	int	a11;
	int	b11;
	int	c11;
	int	d11;
	int	nb12;
	int	nb13;
	int	nb;

	// ex06
	// ft_print_alphabet();
	// ex07
	// ft_print_numbers();
	// ex08
	// ft_is_negative(9);
	// ft_is_negative(-1);
	// ft_is_negative(0);
	// ex09
	ft_ft(&nbr);
	printf("%d\n", nbr);
	// ex10
	a = 10;
	b = 11;
	ft_swap(&a, &b);
	printf("%d, %d\n", a, b);
	// ex11
	a11 = 5;
	b11 = 2;
	ft_div_mod(a11, b11, &c11, &d11);
	printf("%d, %d\n", c11, d11);
	// ex12
	nb12 = 10;
	printf("%d\n", ft_iterative_factorial(nb12)); // 3628800
	// ex13
	nb13 = 10;
	printf("%d\n", ft_recursive_factorial(nb13));
	// ex14
	nb = 10000;
	printf("%d\n", ft_sqrt(nb));
	nb = 100001;
	printf("%d\n", ft_sqrt(nb));
	// ex15
	ft_putstr("Hi\n");
	// ex16
	printf("%d\n", ft_strlen("Hi"));
	// ex17
	printf("%d\n", ft_strcmp("abc", "abc"));
	printf("%d\n", ft_strcmp("abc", "def"));
	printf("%d\n", ft_strcmp("abc", "ab"));
	printf("%d\n", ft_strcmp("ab", "abc"));
	printf("%d\n", ft_strcmp("ab", ""));
	printf("%d\n", ft_strcmp("", "ab"));
	printf("%d\n", ft_strcmp("", ""));
}
