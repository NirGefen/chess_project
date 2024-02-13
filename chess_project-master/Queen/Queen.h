#pragma once
#include "../Piece/Piece.h"
#include "../Rook/Rook.h"
#include "../Bishop/Bishop.h"

class Queen : public Piece
{
public:
	Queen(const bool isWhite, const Square& square);
	moves move(const Board& board, const Square& other) const override;
};

