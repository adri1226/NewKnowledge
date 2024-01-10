#ifndef COORDENATE_H
#define COORDENATE_H

#include <iostream>

class Coordenate
{
public:
	Coordenate() = default;
	Coordenate(int x, int y);

	Coordenate operator+(const Coordenate& coordenate) const;
	friend std::ostream& operator<<(std::ostream& os, const Coordenate& obj);

	int getX() const;
	int getY() const;

private:
	int _x;
	int _y;
};

#endif //COORDENATE_H
