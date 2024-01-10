#include "LanguageFactory.hpp"

std::shared_ptr<Language> LanguageFactory::createLanguage(LanguagesAvailables::Availables languageSelected)
{
    switch (languageSelected)
    {
    case LanguagesAvailables::Availables::english:
        return std::make_shared<English>();

    case LanguagesAvailables::Availables::spanish:
        return std::make_shared<Spanish>();

    default:
        return nullptr;

    }
}
