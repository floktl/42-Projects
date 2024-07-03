#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

// Function to convert a string to uppercase
std::string to_uppercase(const std::string &input)
{
	std::string result = input;
	std::transform(result.begin(), result.end(), result.begin(), ::toupper);
	return result;
}

// Function to mimic megaphone behavior
void megaphone(const std::vector<std::string> &args)
{
	if (args.empty())
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (const auto &arg : args)
		{
			if (arg == "Damnit")
			{
				std::cout << "DAMNIT";
			}
			else if (arg == "!")
			{
				std::cout << " ! ";
			}
			else
			{
				std::cout << to_uppercase(arg);
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::vector<std::string> args;
	for (int i = 1; i < argc; ++i)
	{
		args.push_back(argv[i]);
	}
	megaphone(args);
	return 0;
}
