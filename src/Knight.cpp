#include "Knight.h"

Knight::Knight(): Piece(){
	
}

Knight::Knight(char _color): Piece(_color){
	
}

char Knight::getTypeOfPiece(){
	return 'N';
}

/*
Check if the move made or desired by the player is in a col upper or lower(+-1)
from the original col if it is then the destination row is defined by moving from
de origin row 2 rows(+-2) and if its the opposite(2 col and 1 row) made the move, 
validating that it can only make a move in shape of an L like in classic chess.
*/
bool Knight::verifyPieceMoves(int oRow, int oCol, int dRow, int dCol, Piece* Board[8][8]){
    //Desired destination square is free or has an opposite piece
    if((oCol == dCol + 1) or(oCol == dCol - 1)){
        if((oRow == dRow + 2) or(oRow == dRow - 2)){
            return true;
        }
    }
    if((oCol == dCol + 2) or(oCol == dCol - 2)){
        if((oRow == dRow + 1) or(oRow == dRow - 1)){
            return true;
        }
    }
    return false;
}
