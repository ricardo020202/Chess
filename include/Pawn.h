#ifndef PAWN
#define PAWN

#include "Piece.h"

class Pawn: public Piece{
	public:
		Pawn();
		Pawn(char);
		
		char getTypeOfPiece() override;
		
		bool verifyPieceMoves(int, int, int, int, Piece* Board[8][8]) override;
};

#endif
