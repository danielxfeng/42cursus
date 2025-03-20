# include "Harl.hpp"

int	main(void)
{
	auto harl = Harl();
	harl.complain("debug");
	harl.complain("info");
	harl.complain("error");
	harl.complain("warning");
	return EXIT_SUCCESS;
}
