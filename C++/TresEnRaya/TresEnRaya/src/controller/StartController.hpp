#ifndef INITIALIZEGAMECONTROLLER_HPP
#define INITIALIZEGAMECONTROLLER_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "../view/PlayTurnViewBase.hpp"
#include "../view/PlayTurnIAPlayerView.hpp"
#include "../view/PlayTurnRealPlayerView.hpp"
#include "../view/StartGameViewBase.hpp"
#include "../model/Board.hpp"
#include "../model/Player.hpp"
#include "../model/Players.hpp"
#include "../model/Game.hpp"

class StartController
{
public:
    size_t const MIN_NUMBER_PLAYERS = 2;
    size_t const MAX_NUMBER_PLAYERS = 4;
    size_t const MIN_ROW_COLUMN = 3;
    size_t const MAX_ROW_COLUM = 7;

    StartController(std::shared_ptr<StartGameViewBase> view, std::shared_ptr<Language> language);

    Game initializeGame();
    std::vector<std::shared_ptr<PlayTurnViewBase>> initializePlayTurnViews();

private:
    Board initializeBoard();
    Player intiliazePlayer();
    Player intiliazeIAPlayer();
    Players initiliazePlayers();

    std::shared_ptr<StartGameViewBase>  _view;
    std::vector<Piece> _piecesAvailable;
    std::vector<std::shared_ptr<PlayTurnViewBase>> _viewsPlayTurn;
    std::shared_ptr<Board> _board;
    std::shared_ptr<Language> _language;
};

#endif // INITIALIZEGAMECONTROLLER_HPP
