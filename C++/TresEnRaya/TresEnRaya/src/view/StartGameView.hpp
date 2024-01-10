#ifndef STARTGAMEVIEW_HPP
#define STARTGAMEVIEW_HPP

#include "../view/StartGameViewBase.hpp"

class StartGameView: public StartGameViewBase
{
public:
	StartGameView();
	StartGameView(std::shared_ptr<Language> language);

    std::shared_ptr<Language> getLanguage();
    Dimension getDimension(size_t minimalDimension, size_t maximalDimension, bool incorrect = false);
    std::string getPlayerName();
    std::pair<size_t, Piece> getPiece(std::vector<Piece> piecesAvailable);
    size_t getNumberPlayers(size_t minimalNumberPlayers, size_t maximalNumberPlayers, bool incorrect = false);
    bool isIAPlayer();

private:
    LanguagesAvailables _languagesAvailables;
};

#endif // STARTGAMEVIEW_HPP
