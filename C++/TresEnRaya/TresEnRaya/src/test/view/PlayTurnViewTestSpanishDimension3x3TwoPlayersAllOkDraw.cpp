#include "PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw.hpp"

PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw()
{
    _isTestCorrect = false;
}

PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw(std::shared_ptr<Language> language)
    :PlayTurnViewBase(language)
{
    _isTestCorrect = false;
}

PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw(std::vector<Coordenate> allMoves, std::string nameWinner)
    :_allMoves(allMoves), _nameWinner(nameWinner)
{
    _isTestCorrect = false;
}

PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw(std::shared_ptr<Language> language, std::vector<Coordenate> allMoves, std::string nameWinner)
    :PlayTurnViewBase(language), _allMoves(allMoves), _nameWinner(nameWinner)
{
    _isTestCorrect = false;
}

Coordenate PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::getCoordenate(Dimension boardDimension, const char *playerName, bool incorrect)
{
    Coordenate coordenate = _allMoves.back();
    _allMoves.pop_back();
    return coordenate;
}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::showWinner(const char *playerName)
{
    _isTestCorrect = false;
}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::showBoard(const Board board){}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::showGameDraw()
{
    std::string messageLanguage = _language->getMessage(Language::Message::GameDraw);
    std::string message = "Habeis quedado empate.\n";
    _isTestCorrect = messageLanguage == message;
}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::showProgressBar(){}

void PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::cleanScreen(){}

bool PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw::getIsTestCorrect()
{
    return _isTestCorrect;
}

