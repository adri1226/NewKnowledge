//============================================================================
// Name        : TresEnRaya.cpp
// Author      : Adrian Fenandez Gomez
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unistd.h>
using namespace std;

#include "src/controller/StartController.hpp"
#include "src/controller/PlayTurnController.hpp"
#include "src/view/PlayTurnViewBase.hpp"
#include "src/view/PlayTurnRealPlayerView.hpp"
#include "src/view/PlayTurnIAPlayerView.hpp"
#include "src/view/StartGameView.hpp"
#include "src/model/Language.hpp"

#include "src/test/TestDimension3x3TwoPlayersAllOk.hpp"
#include "src/test/TestDimension3x3TwoPlayersSpanishError.hpp"

int main()
{
    std::shared_ptr<StartGameViewBase> starGameView = std::make_shared<StartGameView>();
    std::shared_ptr<Language> language = starGameView->getLanguage();

    StartController startController(starGameView, language);

    Game game(startController.initializeGame());

    PlayTurnController turnController(game, startController.initializePlayTurnViews());

    turnController.playGame();

    int a = 1;

    cout << "Introduzca un numero para terminar... ";
    cin >> a;

    cout << "Fin de programa" << endl; // prints !!!Hello World!!!
    return 0;
}
