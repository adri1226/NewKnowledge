#ifndef PLAYTURNVIEW_HPP
#define PLAYTURNVIEW_HPP

#include "PlayTurnViewBase.hpp"

class PlayTurnRealPlayerView: public PlayTurnViewBase
{
public:
    PlayTurnRealPlayerView();
    PlayTurnRealPlayerView(std::shared_ptr<Language> language);

    Coordenate getCoordenate(Dimension boardDimension, const char * playerName, bool incorrect = false);
};

#endif // PLAYTURNVIEW_HPP
