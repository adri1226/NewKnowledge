#include "PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk.hpp"

PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk(): PlayTurnViewBase()
{
	_isTestCorrect = true;
	_isNameWinnerCorrect = false;
	_isMessageShowWinnerCorrect = false;
    _numberCallsGetCoordenate = 0;
}

PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk(std::shared_ptr<Language> language): PlayTurnViewBase(language)
{
	_isTestCorrect = true;
	_isNameWinnerCorrect = false;
	_isMessageShowWinnerCorrect = false;
    _numberCallsGetCoordenate = 0;
}

PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk(std::vector<Coordenate> allMoves, std::string nameWinner):
		_allMoves(allMoves), _nameWinner(nameWinner)
{
	_isTestCorrect = true;
	_isNameWinnerCorrect = false;
	_isMessageShowWinnerCorrect = false;
    _numberCallsGetCoordenate = 0;
}

PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk(std::shared_ptr<Language> language, std::vector<Coordenate> allMoves, std::string nameWinner):
		PlayTurnViewBase(language), _allMoves(allMoves), _nameWinner(nameWinner)
{
	_isTestCorrect = true;
	_isNameWinnerCorrect = false;
	_isMessageShowWinnerCorrect = false;
    _numberCallsGetCoordenate = 0;
}

Coordenate PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::getCoordenate(Dimension boardDimension, const char * playerName, bool incorrect)
{
    _numberCallsGetCoordenate++;
    Coordenate coordenate = _allMoves.back();
	_allMoves.pop_back();
	return coordenate;
}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::showWinner(const char * playerName)
{
	std::string sPlayerName = playerName;
	_isNameWinnerCorrect = sPlayerName == _nameWinner;

	std::string messageLanguage = _language->getMessage(Language::Message::PlayerWinner);
    std::string message = "Ha ganado %s ¡ENHORABUENA!\n";

    _isMessageShowWinnerCorrect = messageLanguage == message;

    _isTestCorrect &= _isNameWinnerCorrect;
    _isTestCorrect &= _isMessageShowWinnerCorrect;
}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::showBoard(const Board board){}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::showGameDraw()
{
    _isTestCorrect = false;
}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::showProgressBar(){}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::cleanScreen() {
}

bool PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::getIsTestCorrect()
{
    return _isTestCorrect;
}

int PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::getNumberCallsGetCoordenate()
{
    return _numberCallsGetCoordenate;
}

bool PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::getIsMessageWinnerCorrect()
{
	return _isMessageShowWinnerCorrect;
}

bool PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk::getIsNameWinnerCorrect()
{
	return _isNameWinnerCorrect;
}
