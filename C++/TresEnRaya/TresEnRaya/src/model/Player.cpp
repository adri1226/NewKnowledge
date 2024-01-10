#include "Player.hpp"

Player::Player(std::string name, Piece piece):
    _name(name), _onePiece(piece)
    {}

std::ostream& operator<<(std::ostream& os, const Player& obj)
{
    os << "Nombre: " << obj._name << " Piece: " << obj._onePiece.toString();
    return os;
}

bool Player::operator==(const Player& player) const
{
    return _onePiece == player._onePiece;
}

Piece Player::getPiece()
{
	return _onePiece;
}

std::string Player::getName()
{
    return _name;
}
