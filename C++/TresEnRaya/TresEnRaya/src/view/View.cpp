#include "View.hpp"

View::View()
{
	_language = LanguageFactory::createLanguage(LanguagesAvailables::Availables::english);
}

View::View(std::shared_ptr<Language> language): _language(language)
{}

