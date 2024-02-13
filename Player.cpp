#include "Player.h"

Player::Player()
{

}

// Constructor. Updates the board with the new pieces (according to the pieces string). 
// If a square is not set yet and does not belong to this player, it'll be set to null.
Player::Player(Board& board, bool isWhite, const char* pieces)
{
	char soldiersArr[SOLDIERS_AMOUNT] = { 'K', 'Q', 'R', 'N', 'B', 'P' }; // by default this is white
	unsigned int x = 0, y = 0, currentRow = 0;
	this->_isWhitePlayer = isWhite;

	if (!isWhite) // if black, set it to black
	{
		memcpy(soldiersArr, "kqrnbp", SOLDIERS_AMOUNT * sizeof(char));
	}
	
	for (int i = 0; i < PIECES_STR_LEN; i++) 
	{ // we use if's so we can check with vars rather than with constants
		x = i % 8;
		y = STARTING_ROW - 1;
		currentRow = i;
		if (currentRow > LAST_COLUMN) // if i is above 7, we need to move 1 row down
		{
			currentRow = STARTING_ROW - (currentRow / (LAST_COLUMN + 1)) - 1; 
			// currentRow / 8 will give us the row. Example: 17/8 (since it's unsigned int:) will give 2. 8 - 2 = 6. We moved 2 rows down
		}
		else // if it's below or equal to 7 then it's just the starting row
		{
			currentRow = STARTING_ROW - 1;
		}
		y = currentRow;
		// Now we know the x and y of the current square, and can create the piece at that square

		if (pieces[i] == soldiersArr[KING_POS])
		{
			King* newKing = new King(isWhite, Square(x, y));
			this->_pieces.push_back(newKing);
			board.setBoardPiece(x, y, newKing);
		}
		else if (pieces[i] == soldiersArr[QUEEN_POS])
		{
			Queen* newQueen = new Queen(isWhite, Square(x, y));
			this->_pieces.push_back(newQueen);
			board.setBoardPiece(x, y, newQueen);
		}
		else if (pieces[i] == soldiersArr[ROOK_POS])
		{
			Rook* newRook = new Rook(isWhite, Square(x, y));
			this->_pieces.push_back(newRook);
			board.setBoardPiece(x, y, newRook);
		}
		else if (pieces[i] == soldiersArr[KNIGHT_POS])
		{
			Knight* newKnight = new Knight(isWhite, Square(x, y));
			this->_pieces.push_back(newKnight);
			board.setBoardPiece(x, y, newKnight);
		}
		else if (pieces[i] == soldiersArr[BISHOP_POS])
		{
			Bishop* newBishop = new Bishop(isWhite, Square(x, y));
			this->_pieces.push_back(newBishop);
			board.setBoardPiece(x, y, newBishop);
		}
		else if (pieces[i] == soldiersArr[PAWN_POS])
		{
			Pawn* newPawn = new Pawn(isWhite, Square(x, y));
			this->_pieces.push_back(newPawn);
			board.setBoardPiece(x, y, newPawn);
		}
		else if(pieces[i] == '#') // prevents overriding when the next player uses this constructor
		{
			board.setBoardPiece(x, y, nullptr);
		} // else keep it as it is, so it's not necessary
	}
}

Player::~Player()
{
	for (const Piece* piece : this->_pieces)
	{
		delete piece;
	}
}

/*
	Method returns the king of the player.

	Input:
			void.

	Output:
			The coordinates of the king.
*/
const Square& Player::getKingPos() const
{
	for (unsigned int i = 0; i < this->_pieces.size(); i++)
	{
		if ((this->_pieces[i]->getType() == "K" && this->_isWhitePlayer) ||
			(this->_pieces[i]->getType() == "k" && !this->_isWhitePlayer))
		{
			return this->_pieces[i]->getSquare();
		}
	}

	std::cerr << "King not found!" << std::endl;
	exit(EXIT_FAILURE);
}

// getter for pieces vector
const std::vector<Piece*>& Player::getPieces() const
{
	return this->_pieces;
}