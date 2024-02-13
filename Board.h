#pragma once
#include "Piece/Piece.h"

class Piece;

class Board
{
public:
	Piece* getBoardPiece(int row, int col) const;
	void setBoardPiece(int row, int col, Piece* piece);
	void operator=(const Board& other);

private:
	Piece* _board[MAX_ROW][MAX_COL];
};

