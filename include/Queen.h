#ifndef QUEEN
#define QUEEN

#include "Piece.h"

class Queen: public Piece{
	public:
		Queen();
		Queen(char);
		
		char getTypeOfPiece() override;
		
		bool verifyPieceMoves(int, int, int, int, Piece* Board[8][8]) override;
};

#endif
