#include "Pawn.h"

Pawn::Pawn(): Piece(){
	
}

Pawn::Pawn(char _color): Piece(_color){
	
}

char Pawn::getTypeOfPiece(){
	return 'P';
}

/*
Check if the pawn is able to move, in this case for making it simple, dont allow a 2 square move
at the beginning, then using an if tho check if the desired destination is empty, empty = 0, if
it's empty make the move, by cheking if the move is ade in the same col, this because pawn can 
only move in the same col, except when eating, and defining de desired dest as the orgin +- 1,
depending if it is a white or black piece(going up or going down).
*/
bool Pawn::verifyPieceMoves(int oRow, int oCol, int dRow, int dCol, Piece* Board[8][8]){
    Piece* dest = Board[dRow][dCol];
    if(dest == 0){
        //Check if desired destination is empty
        if(oCol == dCol){
           if(getColor() == 'W'){
            	if(dRow == 3){
            		if(dRow == oRow + 2){
            			return true;
					}else if(dRow == oRow + 1){
                    	return true;
               		}
				}else{
					if(dRow == oRow + 1){
                    	return true;
               		}
				}
            }else{
                if(dRow == 4){
            		if(dRow == oRow - 2){
            			return true;
					}else if(dRow == oRow - 1){
                    	return true;
               		}
				}else{
					if(dRow == oRow - 1){
                    	return true;
               		}
				}
            }

        }
    }else{
        //Check if desired destination has an enemy piece
        if((oCol == dCol + 1) or (oCol == dCol - 1)){
            if(getColor() == 'W'){
                if(dRow == oRow + 1){
                    return true;
                }
            }else{
                if(dRow == oRow - 1){
                    return true;
                }
            }
        }
    }
    return false;
}
