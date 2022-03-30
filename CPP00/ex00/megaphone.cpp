#include <iostream>
#include <string>

#define NOISE	"* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void	print_to_upper(const char *s)
{
	std::string	str(s);

	for (size_t i = 0; i < str.length(); ++i)
		std::cout << (char)std::toupper(str[i]);	
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << NOISE << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
			print_to_upper(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}
