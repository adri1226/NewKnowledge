#include "StartGameViewTestSpanishDimension3x3TwoPlayersAllOk.hpp"

StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::StartGameViewTestSpanishDimension3x3TwoPlayersAllOk(): StartGameViewBase()
{
	initializeNames();
	_isLanguageCorrect = true;
	_numberCalls_getPlayerName = 0;
}

StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::StartGameViewTestSpanishDimension3x3TwoPlayersAllOk(std::shared_ptr<Language> language): StartGameViewBase(language)
{
	initializeNames();
	_isLanguageCorrect = true;
}

std::shared_ptr<Language> StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::getLanguage()
{
	return LanguageFactory::createLanguage(LanguagesAvailables::spanish);
}

Dimension StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::getDimension(size_t minimalDimension, size_t maximalDimension, bool incorrect)
{
	_isLanguageCorrect = _language->getMessage(Language::Message::LanguageChoose) == "Seleccione un idioma de la lista.";
	_isLanguageCorrect = _language->getMessage(Language::Message::LanguageSelected) == "\nLenguaje seleccionado:";
	return Dimension {3,3};
}

std::string StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::getPlayerName()
{
	_numberCalls_getPlayerName++;
	std::string name = _names[0];
	_names.erase(_names.begin());
		// Lanzar excepcion
	return name;
}

std::pair<size_t, Piece> StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::getPiece(std::vector<Piece> piecesAvailable)
{
	return std::make_pair(0, piecesAvailable[0]);
}

size_t StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::getNumberPlayers(size_t minimalNumberPlayers, size_t maximalNumberPlayers, bool incorrect)
{
    return 2;
}

bool StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::isIAPlayer()
{
    return false;
}

int StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::getNumberCallsOfGetPlayerName()
{
	return _numberCalls_getPlayerName;
}

void StartGameViewTestSpanishDimension3x3TwoPlayersAllOk::initializeNames()
{
	_names = std::vector<std::string>{"Ana", "David"};
}
