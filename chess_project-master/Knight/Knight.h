#pragma once
#include "../Piece/Piece.h"
class Knight : public Piece
{
public:
	Knight(const bool isWhite, const Square& square);
	moves move(const Board& board, const Square& other) const override;
};

