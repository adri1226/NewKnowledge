#include "StartGameViewBase.hpp"

StartGameViewBase::StartGameViewBase(): View(){}

StartGameViewBase::StartGameViewBase(std::shared_ptr<Language> language): View(language)
{
	_languagesAvailables = LanguagesAvailables();
}
