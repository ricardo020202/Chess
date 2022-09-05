#include "Game.h"

//Constructor starting player turn with whites.
Game::Game(){
	playerTurn = 'W';
}

Board Game::getChessBoard(){
	return chessBoard;
}

char Game::getPlayerTurn(){
	return playerTurn;
}

void Game::setPlayerTurn(char _playerTurn){
	playerTurn = _playerTurn;
}

/*
Method used to mkae the moves while playing and validating if the desired
move can be made by the selected piece.
*/
void Game::play(Piece* Board[8][8]){
    bool validMove = false;
    int startRow, endRow;
    char startCol, endCol;
    string startMove, endMove;
    do{
        system("CLS");
        chessBoard.displayBoard();
		
        //Get move inputed by the players
        if(getPlayerTurn() == 'W'){
        	cout<<"White's Move from col (a-h), row (1-8): ";cin>>startMove;
		}else{
			cout<<"Black's Move from col (a-h), row (1-8): ";cin>>startMove;
		}
		cout<<"To col (a-h), row (1-8): ";cin>>endMove;
        
        startRow = (startMove[1] - '0') - 1;
        endRow = (endMove[1] - '0') - 1;
        
        //Transform letters to number indices of the matrix for origin col
        if((startMove[0] == 'a') or (startMove[0] == 'A')){
        	startCol = 0;
		}
		else if((startMove[0] == 'b') or (startMove[0] == 'B')){
			startCol = 1;
		}
		else if((startMove[0] == 'c') or (startMove[0] == 'C')){
			startCol = 2;
		}
		else if((startMove[0] == 'd') or (startMove[0] == 'D')){
			startCol = 3;
		}
		else if((startMove[0] == 'e') or (startMove[0] == 'E')){
			startCol = 4;
		}
		else if((startMove[0] == 'f') or (startMove[0] == 'F')){
			startCol = 5;
		}
		else if((startMove[0] == 'g') or (startMove[0] == 'G')){
			startCol = 6;
		}
		else if((startMove[0] == 'h') or (startMove[0] == 'H')){
			startCol = 7;
		}
		
		//Transform letters to number indices of the matrix for destination col
		if((endMove[0] == 'a') or (endMove[0] == 'A')){
    		endCol = 0;
		}
		else if((endMove[0] == 'b') or (endMove[0] == 'B')){
			endCol = 1;
		}
		else if((endMove[0] == 'c') or (endMove[0] == 'C')){
			endCol = 2;
		}
		else if((endMove[0] == 'd') or (endMove[0] == 'D')){
			endCol = 3;
		}
		else if((endMove[0] == 'e') or (endMove[0] == 'E')){
			endCol = 4;
		}
		else if((endMove[0] == 'f') or (endMove[0] == 'F')){
		    endCol = 5;
		}
		else if((endMove[0] == 'g') or (endMove[0] == 'G')){
			endCol = 6;
		}
		else if((endMove[0] == 'h') or (endMove[0] == 'H')){
			endCol = 7;
		}

        //Check if the indices inputed by the player are within the matrix and if origin and destination are not the same
        if((startRow >= 0 and startRow <= 7) and (startCol >= 0 and startCol <= 7) and (endRow >= 0 and endRow <= 7) and (endCol >= 0 and endCol <= 7)){
            Piece* currentPiece = Board[startRow][startCol];
            
            //Check if the piece selected is from the same color as player turn
            if((currentPiece != 0) and (currentPiece->getColor() == getPlayerTurn())){
            	
                //Check if the selected piece can make the move
                if(currentPiece->legalMoves(startRow, startCol, endRow, endCol, Board)){
                    Piece* TempLocation = Board[endRow][endCol];
                    Board[endRow][endCol] = Board[startRow][startCol];
                    //set previous place as free
                    Board[startRow][startCol] = 0;
                    
                    //Check pawn coronation
                	if((currentPiece->getTypeOfPiece() == 'P') and (currentPiece->getColor() == 'W')){
                		if(endRow == 7){
                			char op;
                			cout<<"Choose piece (Queen: Q, Rook: R, Bishop: B or Knight: N): ";cin>>op;
                			if((op == 'Q') or (op == 'q')){
                				Board[endRow][endCol] = new Queen('W');
							}else if((op == 'R') or (op == 'r')){
								Board[endRow][endCol] = new Rook('W');
							}else if((op == 'B') or (op == 'b')){
								Board[endRow][endCol] = new Bishop('W');
							}else if((op == 'N') or (op == 'n')){
								Board[endRow][endCol] = new Knight('W');
							}
						}
					}else if((currentPiece->getTypeOfPiece() == 'P') and (currentPiece->getColor() == 'B')){
						if(endRow == 0){
							char op;
                			cout<<"Choose piece (Queen: Q, Rook: R, Bishop: B or Knight: N): ";cin>>op;
                			if((op == 'Q') or (op == 'q')){
                				Board[endRow][endCol] = new Queen('B');
							}else if((op == 'R') or (op == 'r')){
								Board[endRow][endCol] = new Rook('B');
							}else if((op == 'B') or (op == 'b')){
								Board[endRow][endCol] = new Bishop('B');
							}else if((op == 'N') or (op == 'n')){
								Board[endRow][endCol] = new Knight('B');
							}
						}
					}
					
					//Long and short castle
					if(currentPiece->getTypeOfPiece() == 'K' and currentPiece->getColor() == 'W'){
						if((endRow == 0) and (endCol == 2)){
							Board[0][0] = 0;
							Board[0][3] = new Rook('W');		
						}else if((endRow == 0) and (endCol == 6)){
							Board[0][7] = 0;
							Board[0][5] = new Rook('W');
						}
					}else if(currentPiece->getTypeOfPiece() == 'K' and currentPiece->getColor() == 'B'){
						if((endRow == 7) and (endCol == 2)){
							Board[7][0] = 0;
							Board[7][3] = new Rook('B');		
						}else if((endRow == 7) and (endCol == 6)){
							Board[7][7] = 0;
							Board[7][5] = new Rook('B');
						}
					}
				
                    //Check if current player is not in check
                    if(!getChessBoard().check(getPlayerTurn())){
                        delete TempLocation;
                        validMove = true;
                    }else{
                        Board[startRow][startCol] = Board[endRow][endCol];
                        Board[endRow][endCol] = TempLocation;
                    }
                }
            }
        }
        if(!validMove){
            cout<<"Invalid Move!"<<endl;
        }
    }while(!validMove);
}

/*
Method used to change or alternate withn players turn, first check if the 
current turn is white or "W" if it is change turn to black "B" if not change turn
to white or "W
*/
void Game::changeTurns(){
	if(getPlayerTurn() == 'W'){
		setPlayerTurn('B');
	}else{
		setPlayerTurn('W');
	}
}

/*
Check that the current player can make a move, if not, end match by declaring 
checkmate(one player wins) or boards(tie).
*/
bool Game::gameOver(){
    bool bCanMove(false);
    bCanMove = getChessBoard().canMove(getPlayerTurn());
    if(!bCanMove){
        if(getChessBoard().check(getPlayerTurn())){
            changeTurns();
            if(getPlayerTurn() == 'W'){
            	cout<<"Checkmate, White Wins!" <<endl;
			}else{
				cout<<"Checkmate, Black Wins!" <<endl;
			}
        }else{
            cout<<"Boards!" <<endl;
        }
    }
    return !bCanMove;
}


//Calling and implementing method to start match
void Game::start(){
	do{
		play(chessBoard.board);
        changeTurns();
    }while(!gameOver());
}

//Execute game
int main(){
    Game match;
    
    match.start();
    
	return 0;
}
