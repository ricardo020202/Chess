#include "Queen.h"

Queen::Queen(): Piece(){
	
}

Queen::Queen(char _color): Piece(_color){
	
}

char Queen::getTypeOfPiece(){
	return 'Q';
}

/*
In this case I realized that the piece of the Queen in chess is kind of a 
mix between the biashop (diagonal movement) and the rook (straigh line movement)
so I decided to implement the same code from the bishop and the rook.
*/
bool Queen::verifyPieceMoves(int oRow, int oCol, int dRow, int dCol, Piece* Board[8][8]){
	int rowOffset, colOffset, checkRow, checkCol;
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
    }else if((dCol - oCol == dRow - oRow) or(dCol - oCol == oRow - dRow)){
        //Make sure that squares in the diagonnals are free
        if(dRow - oRow > 0){
        	rowOffset = 1;
		}else{
			rowOffset = -1;
		}
		
		if(dCol - oCol > 0){
			colOffset = 1;
		}
		else{
			colOffset = -1;
		}
        for(checkRow = oRow + rowOffset, checkCol = oCol + colOffset; checkRow !=  dRow; checkRow = checkRow + rowOffset, checkCol = checkCol + colOffset){
            if(Board[checkRow][checkCol] != 0){
                return false;
            }
        }
        return true;
    }
    return false;
}
