#include "King.h"

King::King(const bool isWhite, const Square& square)
{
	this->_isWhitePiece = isWhite;
	this->_pos = square;
	this->_type = isWhite ? "K" : "k";
}

/*
	Method checks if the king move is legal.

	Input:
			board - The game board.
			other - The square to move to.

	Output:
			The move's legality.
*/
moves King::move(const Board& board, const Square& other) const
{
	if (std::abs((int)this->_pos.getX() - (int)other.getX()) > 1 ||
		std::abs((int)this->_pos.getY() - (int)other.getY()) > 1)
	{
		return MOVE_IMPOSSIBLE;
	}

	else if (board.getBoardPiece(other.getX(), other.getY()) != nullptr &&
			board.getBoardPiece(other.getX(), other.getY())->isWhite() == this->_isWhitePiece)
	{
		return MOVE_SELF_CAPTURE;
	}

	return MOVE_VALID;
}