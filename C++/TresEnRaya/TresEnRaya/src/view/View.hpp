#ifndef VIEW_HPP
#define VIEW_HPP

#include <iostream>

#include "../model/Language.hpp"
#include "../others/LanguageFactory.hpp"

class View
{
public:
	View();
	View(std::shared_ptr<Language> language);

protected:
    std::shared_ptr<Language> _language;
};

#endif // VIEW_HPP
