#include "Piece.hpp"

Piece::Piece(Color color): _color(color){}

Piece::Piece(const Piece& piece): _color(piece._color){}

std::ostream& operator<<(std::ostream& os, const Piece& obj)
{
	os << obj.toChar();
    return os;
}

bool Piece::operator==(const Piece& piece) const
{
    return _color == piece._color != Color::None;
}

char Piece::toChar() const
{
    switch (_color)
    {
    case Color::None:
        return '-';
        break;
    case Color::White:
        return 'W';
        break;

    case Color::Black:
        return 'B';
        break;

    case Color::Red:
        return 'R';
        break;

    case Color::Purple:
        return 'P';
        break;

    default:
        return '?';
        break;
    }
}

std::string Piece::toString() const
{
    switch (_color)
    {
    case Color::None:
        return "---";
        break;
    case Color::White:
        return "White";
        break;

    case Color::Black:
        return "Black";
        break;

    case Color::Red:
        return "Red";
        break;

    case Color::Purple:
        return "Purple";
        break;

    default:
        return "???";
        break;
    }
}
