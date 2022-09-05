#ifndef BISHOP
#define BISHOP

#include "Piece.h"

class Bishop: public Piece{
	public:
		Bishop();
		Bishop(char);
		
		char getTypeOfPiece() override;
		
		bool verifyPieceMoves(int, int, int, int, Piece* Board[8][8]) override;
};

#endif
