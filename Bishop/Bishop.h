#pragma once

#include "../Piece/Piece.h"

class Bishop : public Piece
{
public:
	Bishop(const bool isWhite, const Square& square);
	moves move(const Board& board, const Square& other) const override;
};
