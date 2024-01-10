#include "LanguagesAvailables.hpp"

LanguagesAvailables::LanguagesAvailables()
{
	_numberLanguages = 2;
}

size_t LanguagesAvailables::getNumberLanguages()
{
	return _numberLanguages;
}

std::vector<std::string> LanguagesAvailables::toVectorString()
{
	return std::vector<std::string> {"English", "Spanish"};
}
