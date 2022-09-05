#ifndef PIECE
#define PIECE
#include <iostream>

using namespace std;

class Piece{
	protected:
		char color;
	
	public:
		Piece();
		Piece(char);
		
		void setColor(char);
		char getColor();
		
		virtual char getTypeOfPiece() = 0;
		bool legalMoves(int, int, int, int, Piece* Board[8][8]);
		virtual bool verifyPieceMoves(int, int, int, int, Piece* Board[8][8]) = 0;
		
};

#endif
