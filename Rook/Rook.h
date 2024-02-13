#pragma once
#include "../Piece/Piece.h"


class Rook : public Piece
{
public:
	Rook(const bool isWhite, const Square& square);
	moves move(const Board& board, const Square& other) const override;
};
