#include "Pawn.h"


Pawn::Pawn(const bool isWhite, const Square& square)
{
	this->_isWhitePiece = isWhite;
	this->_pos = square;
	this->_type = isWhite ? "P" : "p";
}

/*
	Method checks if the Pawn move is legal.

	Input:
			board - The game board.
			other - The square to move to.

	Output:
			The move's legality.
*/
moves Pawn::move(const Board& board, const Square& other) const
{
	if (this->_isWhitePiece)
	{
		if (board.getBoardPiece(other.getX(), other.getY()) == nullptr)
		{
			if (this->_pos.getY() + 2 == other.getY() &&	//Double advance
				this->_pos.getX() == other.getX() &&
				board.getBoardPiece(this->_pos.getX(), this->_pos.getY() + 1) == nullptr &&
				this->_pos.getY() == 1)
			{
				return MOVE_VALID;
			}

			else if (this->_pos.getY() + 1 == other.getY() &&
				this->_pos.getX() == other.getX()) //Movement / promotion
			{
				if ((this->_isWhitePiece && other.getY() == 7))
				{
					return MOVE_PROMOTION;
				}

				else
				{
					return MOVE_VALID;
				}
			}
		}

		else
		{
			if (std::abs((int)this->_pos.getX() - (int)other.getX()) == 1 &&
				this->_pos.getY() + 1 == other.getY() &&
				!board.getBoardPiece(other.getX(), other.getY())->isWhite()) //Capture
			{
				return MOVE_VALID;
			}
		}

	}

	else
	{
		if (board.getBoardPiece(other.getX(), other.getY()) == nullptr)
		{
			if (this->_pos.getY() - 2 == other.getY() &&
				this->_pos.getX() == other.getX() &&
				board.getBoardPiece(this->_pos.getX(), this->_pos.getY() - 1) == nullptr &&
				this->_pos.getY() == 6)	//Double advance
			{
				return MOVE_VALID;
			}

			else if (this->_pos.getY() - 1 == other.getY() &&
				this->_pos.getX() == other.getX())	//Movement / promotion
			{
				if ((this->_isWhitePiece && other.getY() == 0))
				{
					return MOVE_PROMOTION;
				}

				else
				{
					return MOVE_VALID;
				}
			}
		}


		else
		{
			if (std::abs((int)this->_pos.getX() - (int)other.getX()) == 1 &&
				this->_pos.getY() - 1 == other.getY() &&
				board.getBoardPiece(other.getX(), other.getY())->isWhite())	//capture
			{
				return MOVE_VALID;
			}
		}
		
	}

	return MOVE_IMPOSSIBLE;
}