#include "Piece.h"

Piece::Piece(){
	color = 'B';
}

Piece::Piece(char _color){
	color = _color;
}

void Piece::setColor(char _color){
	color = _color;
}

char Piece::getColor(){
	return color;
}

/*
Check if the move made by the player is legal, define a destination using a Piece object pointer
that holds destination row and column, then used an if to check if the destination square is occupied
this by making occupied squares equal to one, and cheking if there's an enemy piece, if there 
is an enemy piece you get to eat it if there's else if the square is occupied, it return the 
method to check if according to the type of piece the move is legal, for example the movement 
in form of an L of the knight.
*/
bool Piece::legalMoves(int oRow, int oCol, int dRow, int dCol, Piece* Board[8][8]){
    Piece* dest = Board[dRow][dCol];
    if((dest == 0) or(color != dest->getColor())){
        return verifyPieceMoves(oRow, oCol, dRow, dCol, Board);
    }
    return false;
}
