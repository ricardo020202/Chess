#ifndef ROOK
#define ROOK

#include "Piece.h"

class Rook: public Piece{
	public:
		Rook();
		Rook(char);
		
		char getTypeOfPiece() override;
		
		bool verifyPieceMoves(int, int, int, int, Piece* Board[8][8]) override;
};

#endif
