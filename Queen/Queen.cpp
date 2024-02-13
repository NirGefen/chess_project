#include "Queen.h"

Queen::Queen(const bool isWhite, const Square& square)
{
	this->_isWhitePiece = isWhite;
	this->_pos = square;
	this->_type = isWhite ? "Q" : "q";
}


/*
	Method checks if the bishop move is legal.

	Input:
			board - The game board.
			other - The square to move to.

	Output:
			The move's legality.
*/
moves Queen::move(const Board& board, const Square& other) const
{
	moves ret = Rook(this->_isWhitePiece, this->_pos).move(board, other);
	
	if (ret == MOVE_VALID)
	{
		return ret;
	}
	
	else
	{
		ret = Bishop(this->_isWhitePiece, this->_pos).move(board, other);
		return ret;
	}
}