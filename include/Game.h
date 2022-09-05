#ifndef GAME
#define GAME

#include "Board.h"

class Game{
	private:
		Board chessBoard;
		char playerTurn;
	
	public:
		Game();
		
		Board getChessBoard();
		char getPlayerTurn();
		
		void setPlayerTurn(char);
		
		void play(Piece* Board[8][8]);
		void changeTurns();
		bool gameOver();
		void start();
};

#endif
