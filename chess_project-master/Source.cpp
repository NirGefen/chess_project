/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "./Piece/Piece.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <thread>

using std::cout;
using std::endl;
using std::string;

/*enum moves
{
	MOVE_VALID,
	MOVE_CHECK,
	MOVE_MISSING,
	MOVE_SELF_CAPTURE,
	MOVE_SELF_CHECK,
	MOVE_INVALID_SQUARE,
	MOVE_IMPOSSIBLE,
	MOVE_SAME_SQUARE,
	MOVE_MATE
};*/

int main()
{
	srand(time_t(NULL));

	int srcX = 0, srcY = 0, dstX = 0, dstY = 0;
	int moveCode = MOVE_VALID;
	char moveValidChar[2] = { 0 };
	
	std::string dstStr = "xx";
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return 0;
		}
	}
	

	char msgToGraphics[66];
	// msgToGraphics should contain the board string accord the protocol

	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	Game game(msgToGraphics);

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		dstStr[SQUARE_LETTER_POS] = msgFromGraphics[SECOND_SQUARE_LETTER_POS];
		dstStr[SQUARE_NUMBER_POS] = msgFromGraphics[SECOND_SQUARE_NUMBER_POS];
		msgFromGraphics.erase(SECOND_SQUARE_LETTER_POS);
		game.strSquareToInt(msgFromGraphics, srcX, srcY);
		game.strSquareToInt(dstStr, dstX, dstY);
		
		if (game.getBoard().getBoardPiece(srcX, srcY) == nullptr || // prevent using a null object causing program to crash
			(game.getBoard().getBoardPiece(srcX, srcY)->isWhite() && !game.isWhiteTurn()) || // checks if it's white but not white's turn
			(!game.getBoard().getBoardPiece(srcX, srcY)->isWhite() && game.isWhiteTurn())) // checks if it's black but not black's turn
		{
			moveCode = MOVE_MISSING;
		}
		else
		{
			Piece* srcPiece = game.getBoard().getBoardPiece(srcX, srcY);
			Piece* dstPiece = game.getBoard().getBoardPiece(dstX, dstY);
			moveCode = game.getBoard().getBoardPiece(srcX, srcY)->move(game.getBoard(), Square(dstX, dstY));

			if (MOVE_VALID == moveCode || MOVE_CHECK == moveCode || MOVE_MATE == moveCode)
			{
				game.getBoard().setBoardPiece(dstX, dstY, game.getBoard().getBoardPiece(srcX, srcY));
				game.getBoard().getBoardPiece(dstX, dstY)->updatePos(dstX, dstY);
				game.getBoard().setBoardPiece(srcX, srcY, nullptr);
				
				if (game.isInCheck(game.isWhiteTurn()))
				{
					game.getBoard().setBoardPiece(srcX, srcY, srcPiece);
					game.getBoard().getBoardPiece(srcX, srcY)->updatePos(srcX, srcY);
					game.getBoard().setBoardPiece(dstX, dstY, dstPiece);
					if (game.getBoard().getBoardPiece(dstX, dstY) != nullptr)
					{
						game.getBoard().getBoardPiece(dstX, dstY)->updatePos(dstX, dstY);
					}
					moveCode = MOVE_SELF_CHECK;
				}
				else
				{
					game.switchTurn();
				}
			}
		}
		
		moveValidChar[0] = std::to_string(moveCode)[0];
		strcpy_s(msgToGraphics, moveValidChar);
		

		/* JUST FOR EREZ DEBUGGING
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		JUST FOR EREZ DEBUGGING */


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}