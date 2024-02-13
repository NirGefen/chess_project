#include "Game.h"

// Constructor for game. Setup contains the starting board string
Game::Game(const char* setup)
	: _isWhiteTurn(false)
{
	if (!(int)setup[STARTING_CHAR_POS]) // 0, white starts
	{
		this->_isWhiteTurn = true;
	}
	
	this->_black = Player(this->_board, false, setup);
	this->_white = Player(this->_board, true, setup);
}

// getters
Board& Game::getBoard()
{
	return this->_board;
}

bool Game::isWhiteTurn() const
{
	return this->_isWhiteTurn;
}

/*
	Method checks if the specified player is in check.

	Input:
			isWhite - Tells the method which player to check.

	Output:
			true if the specified player is in check.
*/
bool Game::isInCheck(const bool isWhite)
{
	const Player& playerToCheck = isWhite ? this->_black : this->_white;
	const Square& kingPos = isWhite ? this->_white.getKingPos() : this->_black.getKingPos();
	const std::vector<Piece*>& enemyPieces = playerToCheck.getPieces();

	for (unsigned int i = 0; i < enemyPieces.size(); i++)
	{
		if (enemyPieces[i]->move(this->getBoard(), kingPos) == MOVE_VALID)
		{
			return true;
		}
	}
	
	return false;
}


/*
	Method prints out the board.

	Input:
			void.
	
	Output:
			void.
*/
void Game::printBoard() const
{
	for (unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		for (unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << this->_board.getBoardPiece(i, j)->getType() << " ";
		}
		std::cout << std::endl;
	}

	if (this->_isWhiteTurn)
	{
		std::cout << "It's white's turn!" << std::endl;
	}

	else
	{
		std::cout << "it's black's turn!" << std::endl;
	}
}

/*
Converts a square string (like "e2") to x (column) and y (row) in int, location on the board.
Input: strSquare - the string to convert, x - the column to store at, y - the row to store at
Output: none
*/
void Game::strSquareToInt(std::string& strSquare, int& x, int& y)
{
	char letter[1] = { 0 };
	x = (int)strSquare[SQUARE_LETTER_POS] - FIRST_ALLOWED_LETTER_INT; // for 'a', this will be 97-97 = 0 which is the first column in our array
	letter[0] = strSquare[SQUARE_NUMBER_POS]; // get the letter in a char string rather than "string" type
	// atoi will convert the letter to a number, because we need the number itself rather than its ASCII value
	y = std::atoi(letter) - 1; // for '2', this will be 2-1 = 1, which is the second row in our array
}

/*
Setter, switches the turn
Input: none
Output: none
*/
void Game::switchTurn()
{
	this->_isWhiteTurn = !this->_isWhiteTurn;
}