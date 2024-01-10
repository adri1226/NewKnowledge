#ifndef LANGUAGEFACTORY_HPP
#define LANGUAGEFACTORY_HPP

#include "../model/Language.hpp"
#include "../model/Spanish.hpp"
#include "../model/English.hpp"
#include "LanguagesAvailables.hpp"

class LanguageFactory
{
public:
    static std::shared_ptr<Language> createLanguage(LanguagesAvailables::Availables languageSelected);
};

#endif //LANGUAGEFACTORY_HPP
