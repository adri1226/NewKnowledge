#ifndef STARTGAMEVIEWTESTSPANISERRORNUMBERPLAYERS_HPP
#define STARTGAMEVIEWTESTSPANISERRORNUMBERPLAYERS_HPP

#include "../../view/StartGameViewBase.hpp"

// Partida en la que da error al pedir el numero de jugadores
class StartGameViewTestSpanishDimension3x3ErrorNumberPlayers: public StartGameViewBase
{
public:
	StartGameViewTestSpanishDimension3x3ErrorNumberPlayers();
	StartGameViewTestSpanishDimension3x3ErrorNumberPlayers(std::shared_ptr<Language> language);

    std::shared_ptr<Language> getLanguage();
    Dimension getDimension(size_t minimalDimension, size_t maximalDimension, bool incorrect = false);
    std::string getPlayerName();
    std::pair<size_t, Piece> getPiece(std::vector<Piece> piecesAvailable);
    size_t getNumberPlayers(size_t minimalNumberPlayers, size_t maximalNumberPlayers, bool incorrect = false);
    bool isIAPlayer();

    int getNumberCallsOfGetNumberPlayers();
    int getNumberCallsOfGetDimension();

private:
    int _numberCallsOfGetDimension;
    int _numberCallsOFGetNumberPlayers;

};

#endif // STARTGAMEVIEWTESTSPANISERRORNUMBERPLAYERS_HPP
