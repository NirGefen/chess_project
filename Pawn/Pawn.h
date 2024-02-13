#pragma once
#include "../Piece/Piece.h"


//Add en passant
class Pawn : public Piece
{
public:
	Pawn(const bool isWhite, const Square& square);
	moves move(const Board& board, const Square& other) const override;
};

