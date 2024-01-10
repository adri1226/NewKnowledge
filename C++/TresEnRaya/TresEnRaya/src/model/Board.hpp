#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <sstream>

#include "../others/Piece.hpp"
#include "../others/Coordenate.hpp"
#include "../others/Dimension.hpp"

class Board
{
public:
    Board(Dimension dimension);

    bool putPiece(Piece piece, Coordenate coordenate);
    bool isCoodenateCorrect(Coordenate coordenate) const;
    friend std::ostream& operator<<(std::ostream& os, const Board& obj);

    const Dimension& getDimension() const;
    size_t getRows() const;
    size_t getColumns() const;
    const std::shared_ptr<Piece>& getPieceAt(Coordenate coordenate) const;
    std::string toString() const;
    bool isSquareEmpty(Coordenate coordenate) const;

private:
    bool canPutPiece(Coordenate coordenate);

    Dimension _dimension;
    std::vector<std::vector<std::shared_ptr<Piece>>> _board;
    std::shared_ptr<Piece> _nonePiece;
};

#endif // BOARD_HPP
