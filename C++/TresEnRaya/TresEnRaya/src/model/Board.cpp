#include "Board.hpp"

Board::Board(Dimension dimension): _dimension(dimension)
{
    _board.resize(_dimension.numberRows);
    _nonePiece = std::make_shared<Piece>(Piece(Piece::Color::None));
    for(size_t row{0}; row < _dimension.numberRows; row++)
    {
        _board[row].resize(_dimension.numberColumns);
        for(size_t column{0}; column < _dimension.numberColumns; column++)
        {
            _board[row][column] = _nonePiece;
        }
    }
}

bool Board::putPiece(Piece piece, Coordenate coordenate)
{
	if(!canPutPiece(coordenate))
		return false;

	_board[coordenate.getX()][coordenate.getY()] = std::make_shared<Piece>(piece);
	return true;
}

bool Board::isCoodenateCorrect(Coordenate coordenate) const
{
	return (coordenate.getX() >= 0 && coordenate.getX() < getRows()) && (coordenate.getY() >= 0 && coordenate.getY() < getColumns());
}

std::ostream& operator<<(std::ostream& os, const Board& obj)
{
    os << obj.toString();

    return os;
}

const Dimension& Board::getDimension() const
{
    return _dimension;
}

size_t Board::getRows() const
{
	return getDimension().numberRows;
}

size_t Board::getColumns() const
{
	return getDimension().numberColumns;
}

const std::shared_ptr<Piece>& Board::getPieceAt(Coordenate coordenate) const
{
    if(!isCoodenateCorrect(coordenate))
        return std::shared_ptr<Piece>(nullptr);

    return _board[coordenate.getX()][coordenate.getY()];
}

bool Board::canPutPiece(Coordenate point)
{
    if(!isCoodenateCorrect(point))
    {
    	return false;
    }

    if(!isSquareEmpty(point))
    {
        return false;
    }

    return true;
}

std::string Board::toString() const
{
    std::stringstream ssPrint;

	for(size_t row{0}; row < _dimension.numberRows; row++)
    {
        for(size_t column{0}; column < _dimension.numberColumns; column++)
        {
        	ssPrint << "|";
            if(_board[row][column] == _nonePiece)
            {
            	ssPrint << "-";
            }
            else
            {
            	ssPrint << _board[row][column]->toChar();
            }
        }
        ssPrint << "|" << std::endl;
    }
    ssPrint << std::endl;
    return ssPrint.str();
}

bool Board::isSquareEmpty(Coordenate coordenate) const
{
    return _board[coordenate.getX()][coordenate.getY()] == _nonePiece;
}
