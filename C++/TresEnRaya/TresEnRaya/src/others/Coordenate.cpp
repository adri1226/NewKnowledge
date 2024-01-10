#include "Coordenate.hpp"

Coordenate::Coordenate(int x, int y): _x(x), _y(y)
{}

Coordenate Coordenate::operator+(const Coordenate& coordenate) const
{
	Coordenate resultado(_x + coordenate._x, _y + coordenate._y);
	return resultado;
}

std::ostream& operator<<(std::ostream& os, const Coordenate& obj)
{
    os << "x = " << obj._x << ", y = " << obj._y;

    return os;
}

int Coordenate::getX() const
{
	return _x;
}

int Coordenate::getY() const
{
	return _y;
}
