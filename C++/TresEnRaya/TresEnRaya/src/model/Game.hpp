#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Board.hpp"
#include "Players.hpp"
#include "Language.hpp"

class Game
{
public:
    Game(Board board, Players players);

	void increseTurn();
	bool isOver();
	bool putPiece(Piece piece, Coordenate coordenate);
	bool isCoodenateCorrect(Coordenate point);

	std::shared_ptr<Board> getBoard();
	Dimension getDimension();
	Players getPlayers();
	size_t getTurn();
	size_t getNumberPlayers();
	size_t getNumberRows();
	size_t getNumberColumns();
	std::shared_ptr<Piece> getPieceAtTurn(Coordenate coordenate);
	std::shared_ptr<Player> getPlayerByTurn(size_t turn);
	std::shared_ptr<Player> getActualPlayer();

private:
    size_t _turn;
    size_t _numberPlayers;
    std::shared_ptr<Board> _board;
    Players _players;
};

#endif // GAME_H
