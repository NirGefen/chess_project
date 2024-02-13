#pragma once

#include <string>
#include "../Square/Square.h"
#include "../Board.h"

#define BOARD_SIZE 8

enum moves
{
	MOVE_VALID,
	MOVE_CHECK,
	MOVE_MISSING,
	MOVE_SELF_CAPTURE,
	MOVE_SELF_CHECK,
	MOVE_PROMOTION,
	MOVE_IMPOSSIBLE,
	MOVE_SAME_SQUARE,
	MOVE_MATE
};

class Board;

class Piece	//Maybe should be a friend of Game
{
public:
	Piece();
	virtual moves move(const Board& board, const Square& other) const = 0;
	bool isWhite() const;
	const std::string& getType() const;
	const Square& getSquare() const;
	void updatePos(const unsigned int x, const unsigned int y);

protected:
	std::string _type;
	Square _pos;
	bool _isWhitePiece;
};

