#ifndef KING
#define KING

#include "Piece.h"

class King: public Piece{
	public:
		King();
		King(char);
		
		char getTypeOfPiece() override;
		
		bool verifyPieceMoves(int, int, int, int, Piece* Board[8][8]) override;
};

#endif
