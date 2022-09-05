#ifndef BOARD
#define BOARD

#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "King.h"

class Board{
	public:
		Board();
		
		friend ostream& operator <<(ostream&, const Piece&); //Operator overloading
		void displayBoard();
		bool check(char);
		bool canMove(char);
		Piece* board[8][8];
};

#endif
