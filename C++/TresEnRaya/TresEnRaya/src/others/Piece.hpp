#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <ostream>

class Piece
{
public:
	enum Color
	{
	    None,
		White,
	    Black,
	    Red,
	    Purple
	};

    Piece(Color color);
    Piece(const Piece& piece);

    friend std::ostream& operator<<(std::ostream& os, const Piece& obj);
    bool operator==(const Piece&) const;

    char toChar() const;
    std::string toString() const;

private:
    Color _color;
};

#endif // PIECE_HPP
