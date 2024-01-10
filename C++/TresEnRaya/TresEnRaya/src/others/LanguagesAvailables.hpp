#ifndef LANGUAGESAVAILABLES_HPP
#define LANGUAGESAVAILABLES_HPP

#include <iostream>
#include <string>
#include <vector>

class LanguagesAvailables
{
public:
	enum Availables
	{
	    english,
	    spanish
	};

	LanguagesAvailables();

	size_t getNumberLanguages();
	std::vector<std::string> toVectorString();

private:
	size_t _numberLanguages;
};

#endif // LANGUAGESAVAILABLES_HPP
