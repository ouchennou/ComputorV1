#include <iostream>
#include <sstream>
#include<string>
#include <stdlib.h>


bool checkAllDigits(std::string const & word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (!std::isdigit(word[i]))
			return false;
	}
	return !word.empty();
}

void parsePolyEqua(std::string const & str)
{
	int coff[3] = {0,0,0}; 
	std::stringstream streamText(str);
	std::string element;
	int number = 0;
	while (streamText >> element)
	{
		if (checkAllDigits(element))
			number = atoi(element.c_str());
		else if (element.find("^") != std::string::npos)
		{
			std::string degree = element.substr(element.find("^") + 1);
			if (!checkAllDigits(degree))
			{
				std::cout << "Error in the form or the poly" << std::endl;
				exit(1);
			}
			int degreNumber = atoi(degree);
			if (degreNumber > 2)
			{
				std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
				exit(1);
			}
			coff[degreNumber - 1 ] += number;

		}
		// TODO: add a variable to check if we're before the = or after it to change the sign to add or subtract
		// TODO: Reduced Form
		
	}
	// for (int i = 0; i < str.length(); i++)
	// {
	// 	if (std::isdigit(str[i]))
	// 	{

	// 	}

	// }
}



int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	parsePolyEqua(av[1]);
}