#include "../Rook/Rook.h"

Rook::Rook(const bool isWhite, const Square& square)
{
	this->_isWhitePiece = isWhite;
	this->_pos = square;
	this->_type = isWhite ? "R" : "r";
}

/*
	Function moves the rook or throws exception if fails.

	Input:
			board - The game board.
			other - The square to move the rook to.

	Output:
			The move's legality.
*/
moves Rook::move(const Board& board, const Square& other) const
{
	bool sameX = this->_pos.getX() == other.getX();
	bool sameY = this->_pos.getY() == other.getY();

	if (sameX && sameY)
	{
		return MOVE_SAME_SQUARE;
	}
	
	else if (sameX && !sameY)
	{
		if (this->_pos.getY() > other.getY())
		{
			for (unsigned int i = this->_pos.getY() - 1; i > other.getY(); i--)
			{
				if (board.getBoardPiece(this->_pos.getX(), i) != nullptr)
				{
					return MOVE_IMPOSSIBLE;
				}
			}
		}
		
		else
		{
			for (unsigned int i = this->_pos.getY() + 1; i < other.getY(); i++)
			{
				if (board.getBoardPiece(this->_pos.getX(), i) != nullptr)
				{
					return MOVE_IMPOSSIBLE;
				}
			}
		}
	}

	else if (!sameX && sameY)
	{
		if (this->_pos.getX() > other.getX())
		{
			for (unsigned int i = this->_pos.getX() - 1; i > other.getX(); i--)
			{
				if (board.getBoardPiece(i, this->_pos.getY()) != nullptr)
				{
					return MOVE_IMPOSSIBLE;
				}
			}
		}

		else
		{
			for (unsigned int i = this->_pos.getX() + 1; i < other.getX(); i++)
			{
				if (board.getBoardPiece(i, this->_pos.getY()) != nullptr)
				{
					return MOVE_IMPOSSIBLE;
				}
			}
		}
	}

	else
	{
		return MOVE_SAME_SQUARE;
	}
	
	if (board.getBoardPiece(other.getX(), other.getY()) != nullptr &&
		board.getBoardPiece(other.getX(), other.getY())->isWhite() == this->_isWhitePiece)
	{
		return MOVE_SELF_CAPTURE;
	}

	return MOVE_VALID;
}