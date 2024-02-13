#include "Knight.h"

Knight::Knight(const bool isWhite, const Square& square)
{
	this->_isWhitePiece = isWhite;
	this->_pos = square;
	this->_type = isWhite ? "N" : "n";
}


/*
	Method checks if the Knight move is legal.

	Input:
			board - The game board.
			other - The square to move to.

	Output:
			The move's legality.
*/
moves Knight::move(const Board& board, const Square& other) const
{
	if ((std::abs((int)this->_pos.getX() - (int)other.getX()) == 2 &&
		std::abs((int)this->_pos.getY() - (int)other.getY()) == 1) 
		||
		(std::abs((int)this->_pos.getY() - (int)other.getY()) == 2 &&
			std::abs((int)this->_pos.getX() - (int)other.getX()) == 1)
		)
	{
		return MOVE_VALID;
	}

	else
	{
		return MOVE_IMPOSSIBLE;
	}
}
