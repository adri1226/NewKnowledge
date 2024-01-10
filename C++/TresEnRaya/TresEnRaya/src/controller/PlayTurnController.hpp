#ifndef PLAYTURNCONTROLLER_HPP
#define PLAYTURNCONTROLLER_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <future>
#include <atomic>

#include "../model/Game.hpp"
#include "../view/PlayTurnViewBase.hpp"
#include "../others/winvalidator.h"

class PlayTurnController
{
public:
    PlayTurnController(Game game, std::vector<std::shared_ptr<PlayTurnViewBase>> views);

    void playGame();

private:
    bool putPiece(Piece piece, Coordenate coordenate);
    Coordenate playTurn(std::shared_ptr<Player> player);
    bool checkWin(const Coordenate coordenate);
    bool areFinish(std::vector<std::future<bool>> futures);
    bool isPossibleWin(std::vector<std::future<bool>> futures);
    bool checkConditionToWin(const Coordenate coordenate);
    bool checkHalfConditionToWin(const Coordenate coordenate, std::vector<std::vector<Coordenate>> vector);
    bool areTicTacToe(Coordenate coordenate1, Coordenate coordenate2,Coordenate coordenate3);
    bool areEquals(const std::shared_ptr<Piece> first,const std::shared_ptr<Piece> second, const std::shared_ptr<Piece> third);
    void progressCheckCondition();
    std::shared_ptr<PlayTurnViewBase> getViewByTurn(size_t turn);
    std::shared_ptr<PlayTurnViewBase> getActualView();

    Game _game;
//    std::shared_ptr<PlayTurnViewBase>  _view;
    std::vector<std::shared_ptr<PlayTurnViewBase>> _views;
    std::vector<std::vector<Coordenate>> _posibleWins;
    std::atomic<bool> _ischeckConditionToWinInProgress;
    const size_t NUM_THREADS = 3;

    friend class PlayTurnIAPlayerView;
};

#endif // PLAYTURNCONTROLLER_HPP
