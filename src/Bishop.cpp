#include "Bishop.h"

Bishop::Bishop(): Piece(){
	
}

Bishop::Bishop(char _color): Piece(_color){
	
}

char Bishop::getTypeOfPiece(){
	return 'B';
}

/*
Check if the way of the bishop is free(diagonal) by, depending if the piece is white 
or black(up or down) calculates a row and col offset to check each square a t a time 
and will also help to track the path diagonally from the origin all the way to the
desired destination, allowing only diagonals of the color of the origin square 
(white or black in this case "-" or " ") and allowing to eat(replace) opposite pieces.
*/
bool Bishop::verifyPieceMoves(int oRow, int oCol, int dRow, int dCol, Piece* Board[8][8]){
    if((dCol - oCol == dRow - oRow) or(dCol - oCol == oRow - dRow)){
        //Make sure that the squares across the path of th bishop are empty
        int rowOffset, colOffset, checkRow, checkCol;
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
