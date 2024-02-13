#include "Piece.h"

Piece::Piece()
	: _pos(Square(0, 0)), _isWhitePiece(false)
{
}

bool Piece::isWhite() const
{
	return this->_isWhitePiece;
}

const std::string& Piece::getType() const
{
	return this->_type;
}

const Square& Piece::getSquare() const
{
	return this->_pos;
}

/*
	Method updates the coordinates of the piece.

	Input:
			x - The x coordinate.
			y - The y coordinate.

	Output:
			void.
*/
void Piece::updatePos(const unsigned int x, const unsigned int y)
{
	this->_pos.setX(x);
	this->_pos.setY(y);
}