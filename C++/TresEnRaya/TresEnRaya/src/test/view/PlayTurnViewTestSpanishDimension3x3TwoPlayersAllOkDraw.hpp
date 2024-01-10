#ifndef PLAYTURNVIEWTESTSPANISHDIMENSION3X3TWOPLAYERSALLOKDRAW_H
#define PLAYTURNVIEWTESTSPANISHDIMENSION3X3TWOPLAYERSALLOKDRAW_H

#include "../../view/PlayTurnViewBase.hpp"

class PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw: public PlayTurnViewBase
{
public:
    PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw();
    PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw(std::shared_ptr<Language> language);
    PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw(std::vector<Coordenate> allMoves, std::string nameWinner);
    PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOkDraw(std::shared_ptr<Language> language, std::vector<Coordenate> allMoves, std::string nameWinner);

    Coordenate getCoordenate(Dimension boardDimension, const char * playerName, bool incorrect = false);
    void showWinner(const char * playerName) override;
    void showBoard(const Board board) override;
    void showGameDraw() override;
    void showProgressBar() override;
    void cleanScreen() override;

    bool getIsTestCorrect();

private:
    std::vector<Coordenate> _allMoves;
    std::string _nameWinner;
    bool _isTestCorrect;
};

#endif // PLAYTURNVIEWTESTSPANISHDIMENSION3X3TWOPLAYERSALLOKDRAW_H
