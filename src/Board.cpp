#include "Board.h"

/*
Constructor of the board, that firsts places al the squaresn(matrix indices)
as empty "0", then placing all the pieces in its traditional place, first
white and then black pawn using a for cycle and then the rest of the pieces.
*/
Board::Board(){
	//For cycle used to asign all Squares as 0 or empty at the beginning
	for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
            board[row][col] = 0;
        }
    }
    
    //Place black and white pawns
    for (int i = 0; i < 8; ++i) {
            board[1][i] = new Pawn('W');
            board[6][i] = new Pawn('B');
    }
    
    //Place white pieces in the board according to its traditional place
    board[0][0] = new Rook('W');
	board[0][1] = new Knight('W');
    board[0][2] = new Bishop('W');
    board[0][3] = new Queen('W');
    board[0][4] = new King('W');
    board[0][5] = new Bishop('W');
    board[0][6] = new Knight('W');
    board[0][7] = new Rook('W');
    
    //Place place black pieces in the board according to its traditional place
    board[7][0] = new Rook('B');
    board[7][1] = new Knight('B');
    board[7][2] = new Bishop('B');
    board[7][3] = new Queen('B');
    board[7][4] = new King('B');
    board[7][5] = new Bishop('B');
    board[7][6] = new Knight('B');
    board[7][7] = new Rook('B');
}

/*
Operator << overloading used for cout at the same time the type and color 
of a piece in its square.
*/
ostream& operator <<(ostream& os, Piece* piece){
	char color = piece->getColor();
	char type = piece->getTypeOfPiece();
	os<<color<<type; 
	return os;
}

/*
Method used to print in console the chess board with the respective pieces
in its place, an also printing a reference for helpeing the players to choose
the coordinates correctly, by printing 1-8 in left side and a-h in bottom side.
of the board.
*/
void Board::displayBoard(){
    const int squareWidith = 3;
    const int squareHeight = 3;
    cout<<"    ________________________________________________________________________"<<endl;
    for(int row = 0; row < 8*squareHeight; ++row){
        int squareRow = row/squareHeight;
        //Print left numbers
		if(row % 3 == 1){
            cout<<' '<<(char)('1' + 7 - squareRow)<<' ';
        }else{
            cout<<"   ";
        }
        //Print right border
        if((row % 3 == 0 or row % 3 == 1 or row % 3 == 2)){
            cout<<'|';
        }
        //Print the board and pieces in its place
        for(int col = 0; col < 8*squareWidith; ++col){
            int squareCol = col/squareWidith, blanc =0;
            if(((row % 3) == 1) and (col % 3) == 1 and board[7-squareRow][squareCol] != 0){
                cout<<" "<<board[7-squareRow][squareCol];
            }else{
                if((squareRow + squareCol) % 2 == 1){
                    cout<<" - ";
                }else{
                	cout<<"   ";
				}
            }
        }
        //Print left border
		if((row % 3 == 0 or row % 3 == 1 or row % 3 == 2)){
            cout<<'|';
        }
        cout<<endl;
    }
    //Print bottom letters
    cout<<"   |________________________________________________________________________|"<<endl<<endl;
    cout<<"        a        b        c        d        e        f        g        h"<<endl<<endl;
}

/*
Method used to check if the king is in chekmate, by using two nested for cycles to search 
in every square of the board for the king, using the getTypeOfPiece() method and checking 
if its a K of king and using three ifs to determine if the square is occupied, its color 
and position, the using the method legalmoves, giving as parameters the possition of the 
king, checking if any piece can make a move to the king position or eat it. 
*/
bool Board::check(char _color){
    //Check every square looking for the king within the board
    int kingRow;
    int kingCol;
    for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
            if(board[row][col] != 0){
                if(board[row][col]->getColor() == _color){
                    if(board[row][col]->getTypeOfPiece() == 'K'){
                        kingRow = row;
                        kingCol = col;
                    }
                }
            }
        }
    }
    //Check if any enemy piece can declare check.
    for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
            if(board[row][col] != 0){
                if(board[row][col]->getColor() != _color){
                    if(board[row][col]->legalMoves(row, col, kingRow, kingCol, board)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

/*
Method used to check if wether a piece can make a move and if the king is in check.
*/
bool Board::canMove(char _color){
    //Check al pieces in board
    for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
            if(board[row][col] != 0){
                //Check if piece is from the current player and if it can make any move.
                if(board[row][col]->getColor() == _color){
                    for(int moveRow = 0; moveRow < 8; ++moveRow){
                        for(int moveCol = 0; moveCol < 8; ++moveCol){
                            if(board[row][col]->legalMoves(row, col, moveRow, moveCol, board)){
                                //Make move and check if the king is in check.
                                Piece* TempLocation = board[moveRow][moveCol];
                                board[moveRow][moveCol] = board[row][col];
                                board[row][col] = 0;
                                bool bCanMove = !check(_color);
                                //if its in check undo move until king is not in check.
                                board[row][col] = board[moveRow][moveCol];
                                board[moveRow][moveCol] = TempLocation;
                                if(bCanMove){
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
