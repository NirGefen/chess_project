#pragma once

#include "../Piece/Piece.h"

class King : public Piece
{
public:
	King(const bool isWhite, const Square& square);
	moves move(const Board& board, const Square& other) const override;
};
