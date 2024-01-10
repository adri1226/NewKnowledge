#ifndef STARTGAMEVIEWBASE_HPP
#define STARTGAMEVIEWBASE_HPP

#include <sstream>
#include <string>
#include <vector>

#include "../view/View.hpp"
#include "../others/Piece.hpp"
#include "../others/Dimension.hpp"
#include "../others/LanguagesAvailables.hpp"

class StartGameViewBase: public View
{
public:
	StartGameViewBase();
	StartGameViewBase(std::shared_ptr<Language> language);

    virtual std::shared_ptr<Language> getLanguage() = 0;
    virtual Dimension getDimension(size_t minimalDimension, size_t maximalDimension, bool incorrect = false) = 0;
    virtual std::string getPlayerName() = 0;
    virtual std::pair<size_t, Piece> getPiece(std::vector<Piece> piecesAvailable) = 0;
    virtual size_t getNumberPlayers(size_t minimalNumberPlayers, size_t maximalNumberPlayers, bool incorrect = false) = 0;
    virtual bool isIAPlayer() = 0;

protected:
    LanguagesAvailables _languagesAvailables;
};

#endif // STARTGAMEVIEWBASE_HPP
