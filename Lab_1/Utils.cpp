#include "Utils.h"


namespace Utils
{
	std::vector<std::string> Split(std::string str, char delimetr)
	{
		std::vector<std::string> tokens;
		std::string line;
		std::stringstream ss(str);

		while (std::getline(ss, line, ' '))
		{
			tokens.push_back(line);
		}

		return tokens;
	}
}