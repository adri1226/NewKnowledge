#ifndef PLAYTURNVIEWBASE_HPP
#define PLAYTURNVIEWBASE_HPP

#include <chrono>
#include <thread>
#include <string.h>

#include "../view/View.hpp"
#include "../model/Board.hpp"
#include "../others/Coordenate.hpp"
#include "../others/Dimension.hpp"

class PlayTurnViewBase: public View
{
public:
	PlayTurnViewBase();
	PlayTurnViewBase(std::shared_ptr<Language> language);

	virtual Coordenate getCoordenate(Dimension boardDimension, const char * playerName, bool incorrect = false) = 0;
    virtual void showWinner(const char * playerName);
    virtual void showBoard(const Board board);
    virtual void showGameDraw();
    virtual void showProgressBar();
    virtual void cleanScreen();
};

#endif // PLAYTURNVIEWBASE_HPP
