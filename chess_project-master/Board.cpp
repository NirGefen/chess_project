#include "Board.h"

/*
Retrieves a piece at a given location
Input: row - row of the piece, col - the column of the peice
Output Piece* - the piece at board[row][col]
*/
Piece* Board::getBoardPiece(int row, int col) const
{
	return this->_board[row][col];
}

/*
Sets a piece at a given location
Input: row - the row to set the piece to, col - the column to set the piece to, piece - the piece to set
Output: none
*/
void Board::setBoardPiece(int row, int col, Piece* piece)
{
	this->_board[row][col] = piece;
}

/*
	Operator copies the other board to this board.

	Input:
			other - The other board to copy from.

	Output:
			void.
*/
void Board::operator=(const Board& other)
{
	for (unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			this->setBoardPiece(i, j, other.getBoardPiece(i, j));
		}
	}
}