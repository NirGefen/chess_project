#pragma once
#include <iostream>
#include <vector>
#include "King/King.h"
#include "Queen/Queen.h"
#include "Rook/Rook.h"
#include "Knight/Knight.h"
#include "Bishop/Bishop.h"
#include "Pawn/Pawn.h"
#include "Board.h"

// starting player pos in the string
#define STARTING_CHAR_POS 66 // starting from 0, so char 65 is + 1

// these are for the constructor to correctly find the right pieces
#define SOLDIERS_AMOUNT 6 // there are 6 TYPES of soldiers
#define PIECES_STR_LEN 67 // 66 is NULL, so string is 67

// positions in our soldiers array
enum
{
	KING_POS,
	QUEEN_POS,
	ROOK_POS,
	KNIGHT_POS,
	BISHOP_POS,
	PAWN_POS
};

#define STARTING_ROW 8
#define LAST_COLUMN 7

class Player
{
public:
	Player();
	Player(Board& board, bool isWhite, const char* pieces);
	~Player();

	const Square& getKingPos() const;
	const std::vector<Piece*>& getPieces() const;

private:
	std::vector<Piece*> _pieces;
	bool _isWhitePlayer;
};

