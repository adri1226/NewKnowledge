#ifndef PLAYTURNVIEWTESTTOWPLAYERSALLOK_HPP
#define PLAYTURNVIEWTESTTOWPLAYERSALLOK_HPP

#include "../../view/PlayTurnViewBase.hpp"

class PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk: public PlayTurnViewBase
{
public:
	PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk();
	PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk(std::shared_ptr<Language> language);
	PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk(std::vector<Coordenate> allMoves, std::string nameWinner);
	PlayTurnViewTestSpanishDimension3x3TwoPlayersAllOk(std::shared_ptr<Language> language, std::vector<Coordenate> allMoves, std::string nameWinner);

    Coordenate getCoordenate(Dimension boardDimension, const char * playerName, bool incorrect = false);
    void showWinner(const char * playerName) override;
    void showBoard(const Board board) override;
    void showGameDraw() override;
    void showProgressBar() override;
    void cleanScreen() override;

    bool getIsMessageWinnerCorrect();
    bool getIsNameWinnerCorrect();
    bool getIsTestCorrect();
    int getNumberCallsGetCoordenate();

private:
    std::vector<Coordenate> _allMoves;
    std::string _nameWinner;
    bool _isMessageShowWinnerCorrect;
    bool _isNameWinnerCorrect;
    bool _isTestCorrect;
    int _numberCallsGetCoordenate;
};

#endif // PLAYTURNVIEWTESTTOWPLAYERSALLOK_HPP
