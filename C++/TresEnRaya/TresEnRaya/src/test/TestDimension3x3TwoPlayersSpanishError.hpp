#ifndef TESTERROR_HPP
#define TESTERROR_HPP

#include "../controller/PlayTurnController.hpp"
#include "../controller/StartController.hpp"
#include "../view/PlayTurnViewBase.hpp"
#include "../view/StartGameViewBase.hpp"
#include "view/StartGameViewTestSpanishDimension3x3ErrorNumberPlayers.hpp"
#include "view/StartGameViewTestSpanishDimension3x3TwoPlayersAllOk.hpp"
#include "view/PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk.hpp"

class TestDimension3x3TwoPlayersSpanishError
{
public:
	TestDimension3x3TwoPlayersSpanishError();

	void IncorrectDimensionAndNumberPlayers();
    void IncorrectCoordenate();
private:

};

#endif // TESTERROR_HPP
