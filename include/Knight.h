#ifndef KNIGHT
#define KNIGHT

#include "Piece.h"

class Knight: public Piece{
	public:
		Knight();
		Knight(char);
		
		char getTypeOfPiece() override;
		
		bool verifyPieceMoves(int, int, int, int, Piece* Board[8][8]) override;
};

#endif
