#include "Rook.h"

Rook::Rook(): Piece(){
	
}

Rook::Rook(char _color): Piece(_color){
	
}

char Rook::getTypeOfPiece(){
	return 'R';
}

/*
First check if the destination proposed by the player is in the same col than in the 
origin, using a col offset and a row offset, this to move square bys square all the
way to the desired destination, this offset depending if it is a black or white piece 
will be +-1(up or down), in this case using a for cycle it will check if that col is free 
to move and if it is made the move in a straight line across columns, but if the 
columns change and the row are the same, then it will check if that row is free 
and made the move but across rows.
*/
bool Rook::verifyPieceMoves(int oRow, int oCol, int dRow, int dCol, Piece* Board[8][8]){
	int colOffset, rowOffset; 
	
    if(oRow == dRow){
        //Make sure that the squares of the col are empty
		if(dCol - oCol > 0){
			colOffset = 1;
		}else{
			colOffset = -1;
		}
		
        for(int checkCol = oCol + colOffset; checkCol !=  dCol; checkCol = checkCol + colOffset){
            if(Board[oRow][checkCol] != 0){
                return false;
            }
        }
        return true;
    }else if(dCol == oCol){
        //Make sure that the squares of the row are empty
        if(dRow - oRow > 0){
			rowOffset = 1;
		}else{
			rowOffset = -1;
		}
		
        for(int checkRow = oRow + rowOffset; checkRow !=  dRow; checkRow = checkRow + rowOffset){
            if(Board[checkRow][oCol] != 0){
                return false;
            }
        }
        return true;
    }
    return false;
}
