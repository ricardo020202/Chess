#include "King.h"

King::King(): Piece(){
	
}

King::King(char _color): Piece(_color){
	
}

char King::getTypeOfPiece(){
	return 'K';
}

/*
In this case th King piece is very similar to the Queen piece, in terms of the
path he makes when he moves, the only difference is that the king piece can
only moves 1 square at a time, so here we use a vaariable to know if the 
desried destination is one square away from the origin, this by making a substraction
between origin col and row, and destination col and row, validating if this is 
equal bigger or smaller than 1 and 1 and also allow castle if possible.
*/
bool King::verifyPieceMoves(int oRow, int oCol, int dRow, int dCol, Piece* Board[8][8]){
    int rowDelta = dRow - oRow;
    int colDelta = dCol - oCol; 
    
    if(((rowDelta >= -1) and (rowDelta <= 1)) and ((colDelta >= -1) and (colDelta <= 1))){
    	return true;
    }
	else if(((rowDelta == 0)) and ((colDelta >= -2) and (colDelta <= 2))){
    	if(dRow == 0 or dRow == 7){
    		int colOffset;
    		if(dCol - oCol > 0){
				colOffset = 1;
			}else{
				colOffset = -1;
			}
	        for(int checkCol = oCol + colOffset; checkCol <  dCol; checkCol = checkCol + colOffset){
	            if(Board[oRow][checkCol] != 0){
	                return false;
	            }
	        }
	        return true;
		}else{
			return false;
		}
	}
    return false;
}
