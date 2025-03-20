# include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return EXIT_FAILURE;
	auto harl = Harl();
	
	harl.complain(argv[1]);
	return EXIT_SUCCESS;
}
