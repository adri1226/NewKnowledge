#ifndef STARTGAMEVIEWTESTSPANISHALLOK_HPP
#define STARTGAMEVIEWTESTSPANISHALLOK_HPP

#include "../../view/StartGameViewBase.hpp"

// Partida en español, con un tablero de 3x3 y 2 jugadores
class StartGameViewTestSpanishDimension3x3TwoPlayersAllOk: public StartGameViewBase
{
public:
	StartGameViewTestSpanishDimension3x3TwoPlayersAllOk();
	StartGameViewTestSpanishDimension3x3TwoPlayersAllOk(std::shared_ptr<Language> language);

    std::shared_ptr<Language> getLanguage();
    Dimension getDimension(size_t minimalDimension, size_t maximalDimension, bool incorrect = false);
    std::string getPlayerName();
    std::pair<size_t, Piece> getPiece(std::vector<Piece> piecesAvailable);
    size_t getNumberPlayers(size_t minimalNumberPlayers, size_t maximalNumberPlayers, bool incorrect = false);
    bool isIAPlayer();

    int getNumberCallsOfGetPlayerName();

private:
    void initializeNames();

    std::vector<std::string> _names;
    bool _isLanguageCorrect;
    int _numberCalls_getPlayerName;
};

#endif // STARTGAMEVIEWTESTSPANISHALLOK_HPP
