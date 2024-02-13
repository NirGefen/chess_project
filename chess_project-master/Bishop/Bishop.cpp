#include "Bishop.h"

Bishop::Bishop(const bool isWhite, const Square& square)
{
	this->_isWhitePiece = isWhite;
	this->_pos = square;
	this->_type = isWhite ? "B" : "b";
}

/*
	Method checks if the bishop move is legal.

	Input:
			board - The game board.
			other - The square to move to.

	Output:
			The move's legality.
*/
moves Bishop::move(const Board& board, const Square& other) const
{
	bool isXbigger = this->_pos.getX() > other.getX();
	bool isYbigger = this->_pos.getY() > other.getY();
	
	if(isXbigger && isYbigger)
	{
		unsigned int i = this->_pos.getX() - 1, j = this->_pos.getY() - 1;
		while (i > other.getX() && j > other.getY())
		{
			if (board.getBoardPiece(i, j) != nullptr)
			{
				return MOVE_IMPOSSIBLE;
			}

			i--;
			j--;
		}

		if (i != other.getX() || j != other.getY())
		{
			return MOVE_IMPOSSIBLE;
		}
	}

	else if (isXbigger && !isYbigger)
	{
		unsigned int i = this->_pos.getX() - 1, j = this->_pos.getY() + 1;
		while (i > other.getX() && j < other.getY())
		{
			if (board.getBoardPiece(i, j) != nullptr)
			{
				return MOVE_IMPOSSIBLE;
			}

			i--;
			j++;
		}

		if (i != other.getX() || j != other.getY())
		{
			return MOVE_IMPOSSIBLE;
		}
	}

	else if(!isXbigger && isYbigger)
	{
		unsigned int i = this->_pos.getX() + 1, j = this->_pos.getY() - 1;
		while (i < other.getX() && j > other.getY())
		{
			if (board.getBoardPiece(i, j) != nullptr)
			{
				return MOVE_IMPOSSIBLE;
			}

			i++;
			j--;
		}

		if (i != other.getX() || j != other.getY())
		{
			return MOVE_IMPOSSIBLE;
		}
	}

	else
	{
		unsigned int i = this->_pos.getX() + 1, j = this->_pos.getY() + 1;
		while (i < other.getX() && j < other.getY())
		{
			if (board.getBoardPiece(i, j) != nullptr)
			{
				return MOVE_IMPOSSIBLE;
			}

			i++;
			j++;
		}

		if (i != other.getX() || j != other.getY())
		{
			return MOVE_IMPOSSIBLE;
		}
	}

	if (board.getBoardPiece(other.getX(), other.getY()) != nullptr &&
		board.getBoardPiece(other.getX(), other.getY())->isWhite() == this->isWhite())
	{
		return MOVE_SELF_CAPTURE;
	}

	return MOVE_VALID;
}