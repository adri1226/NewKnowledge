#include "winvalidator.h"

WinValidator::WinValidator(std::shared_ptr<const Board> board): _board(board)
{
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, 0), Coordenate(2, 0)});
        // Las dos coordenadas a la derecha en la misma fila
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(-1, 0), Coordenate(-2, 0)});
        // Las dos coordenadas a la izquierda en la misma fila
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(0, 1), Coordenate(0, 2)});
        // Las dos coordenadas encima en la misma columna
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(0, -1), Coordenate(0, -2)});
        // Las dos coordenadas debajo en la misma columna
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(-1, 0), Coordenate(1, 0)});
        // Las dos coordenadas una a la izquierda en la fila y la otra en la derecha de la fila
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(0, 1), Coordenate(0, -1)});
        // Las dos coordenadas una encima en la columna y la otra debajo en la columna
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, 1), Coordenate(2, 2)});
        // Las dos coordenadas de la diagonal de la derecha en la fila y arriba en la columna
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, -1), Coordenate(2, -2)});
        // Las dos coordenadas de la diagonal de la derecha en la fila y debajo en la columna
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(-1, 1), Coordenate(-2, 2)});
        // Las dos coordenadas de la diagonal de la izquierda en la fila y arriba en la columna
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(-1, -1), Coordenate(-2, -2)});
        // Las dos coordenadas de la diagonal de la izquierda en la fila y abajo en la columna
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, 1), Coordenate(-1, -1)});
        // Las dos coordenadas de la diagonal una a la dercha y arriba, y la otra a la izquierda y debajo
    _posibleWins.push_back(std::vector<Coordenate>{Coordenate(1, -1), Coordenate(-1, 1)});
     // Las dos coordenadas de la diagonal una a la derecha y abajo, y la otra a la izquierda y encima
}

bool WinValidator::isWin(const Coordenate coordenate)
{
    bool isWin{false};
    size_t actualPosition{0};


    while(!isWin && actualPosition < _posibleWins.size())
    {
        Coordenate coordenate2 = coordenate + _posibleWins[actualPosition][0];
        Coordenate coordenate3 = coordenate + _posibleWins[actualPosition][1];

        isWin = areTicTacToe(coordenate, coordenate2, coordenate3);

        actualPosition++;
    }


    return isWin;
}

bool WinValidator::areTicTacToe(Coordenate coordenate1, Coordenate coordenate2,Coordenate coordenate3)
{

    if(_board->isCoodenateCorrect(coordenate1) && _board->isCoodenateCorrect(coordenate2) && _board->isCoodenateCorrect(coordenate3))
    {
        return areEquals(_board->getPieceAt(coordenate1), _board->getPieceAt(coordenate2), _board->getPieceAt(coordenate3));
    }

    return false;
}

bool WinValidator::areEquals(const std::shared_ptr<Piece> first,const std::shared_ptr<Piece> second, const std::shared_ptr<Piece> third)
{
    if(first != nullptr && second != nullptr && third != nullptr)
    {
        if(*first == *second && *first == *third)
        {
            return true;
        }
    }

    return false;
}
