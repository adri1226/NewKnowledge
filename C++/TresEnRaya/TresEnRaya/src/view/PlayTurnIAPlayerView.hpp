#ifndef PLAYTURNIAPLAYERVIEW_H
#define PLAYTURNIAPLAYERVIEW_H

#include <cstdlib>
#include <ctime>

#include "PlayTurnViewBase.hpp"
#include "../others/winvalidator.h"

class PlayTurnIAPlayerView: public PlayTurnViewBase
{
public:
    PlayTurnIAPlayerView();
    PlayTurnIAPlayerView(std::shared_ptr<Language> language);
    PlayTurnIAPlayerView(std::shared_ptr<Language> language, std::shared_ptr<const Board> board);

    Coordenate getCoordenate(Dimension boardDimension, const char * playerName, bool incorrect = false);

private:
    void initializePosibleWins();
    std::vector<Coordenate> getEmptySquareInBoard(Dimension boardDimension);
    Coordenate getPossibleWin(std::vector<Coordenate> coordenatePosibleWin);

    std::shared_ptr<const Board> _board;
    std::vector<std::vector<Coordenate>> _posibleWins;
};

#endif // PLAYTURNIAPLAYERVIEW_H
