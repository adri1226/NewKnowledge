#include "Game.hpp"

Game::Game(Board board, Players players):
	_board(std::make_shared<Board>(board)), _players(players)
{
	_turn = 0;
	_numberPlayers = _players.getNumberPlayers();
}

void Game::increseTurn(){
	_turn++;
}

bool Game::isOver()
{
	return _turn == (getNumberRows() * getNumberColumns() - 1);
}

bool Game::putPiece(Piece piece, Coordenate coordenate)
{
	return _board->putPiece(piece, coordenate);
}

bool Game::isCoodenateCorrect(Coordenate coordenate)
{
    return _board->isCoodenateCorrect(coordenate);
}

std::shared_ptr<Board> Game::getBoard()
{
	return _board;
}

Dimension Game::getDimension()
{
	return _board->getDimension();
}

Players Game::getPlayers()
{
	return _players;
}

size_t Game::getTurn()
{
	return _turn;
}

size_t Game::getNumberPlayers()
{
	return _numberPlayers;
}

size_t Game::getNumberRows()
{
	return _board->getRows();
}

size_t Game::getNumberColumns()
{
	return _board->getColumns();
}

std::shared_ptr<Piece> Game::getPieceAtTurn(Coordenate coordenate)
{
	return _board->getPieceAt(coordenate);
}

std::shared_ptr<Player> Game::getPlayerByTurn(size_t turn)
{
    return _players.getPlayerAt(turn % _numberPlayers);
}

std::shared_ptr<Player> Game::getActualPlayer()
{
	return getPlayerByTurn(getTurn());
}
