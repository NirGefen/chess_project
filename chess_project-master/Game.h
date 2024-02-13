#pragma once
#include <iostream>
#include "./Piece/Piece.h"
#include "Player.h"
#include "Board.h"

#define MAX_PLAYERS 2
#define PLAYER_WHITE 0
#define PLAYER_BLACK 1

#define FIRST_ALLOWED_LETTER_INT 97 

// indexes for string square (like "e2"), so we find the letters/numbers
#define SQUARE_LETTER_POS 0
#define SQUARE_NUMBER_POS 1
#define SECOND_SQUARE_LETTER_POS 2
#define SECOND_SQUARE_NUMBER_POS 3

class Game
{
public:
	Game(const char* setup);
	bool isWhiteTurn() const; // getter for _isWhiteTurn
	bool isInCheck(const bool isWhite);
	void switchTurn();
	void printBoard() const;
	Board& getBoard();
	void strSquareToInt(std::string& strSquare, int& x, int& y);

private:
	Player _black;
	Player _white;
	bool _isWhiteTurn;
	Board _board;
};

