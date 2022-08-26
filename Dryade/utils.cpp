#include "utils.h"

std::vector<std::string> split( std::string str, char delimiter)
{
	std::vector<std::string> result;
	std::istringstream f(str);
	for (std::string splitEl; std::getline(f, splitEl, delimiter);) {
		result.push_back(splitEl);
	}
	return result;
}