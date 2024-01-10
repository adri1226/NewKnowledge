#ifndef WINVALIDATOR_H
#define WINVALIDATOR_H

#include <iostream>
#include <thread>
#include <vector>

#include "Coordenate.hpp"
#include "Piece.hpp"
#include "../model/Board.hpp"

class WinValidator
{
public:
    WinValidator(std::shared_ptr<const Board> board);

    bool isWin(const Coordenate coordenate);

private:
    bool areTicTacToe(Coordenate coordenate1, Coordenate coordenate2,Coordenate coordenate3);
    bool areEquals(const std::shared_ptr<Piece> first,const std::shared_ptr<Piece> second, const std::shared_ptr<Piece> third);

    std::vector<std::vector<Coordenate>> _posibleWins;
    std::shared_ptr<const Board> _board;
};

#endif // WINVALIDATOR_H
