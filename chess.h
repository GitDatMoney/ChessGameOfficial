//chess.h
#include <iostream>

using namespace std;
#include "chessPiece.h"

//Class that contains the "board" which holds all the chessPiece objects
class chess {

private:
	//Changed the point to a double pointer
	chessPiece** chessPieceArray;

public:
	chess();
	void move(int x1, int y1, int x2, int y2);
	void printBoard();
};

chess::chess() {
	//Initializes the chessPieceArray
	chessPieceArray = new chessPiece*[8];
	for(int i = 0; i < 8; i++) {
		chessPieceArray[i] = new chessPiece[8];
	}

	for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				chessPieceArray[i][j] = Pawn('W');
			}
		}

}

//Calls pieceMove on the chessPiece object located at the position in the array and passes the new position and the current array
void chess::move(int x1, int y1, int x2, int y2) {
	chessPieceArray[x1][y1].pieceMove(x2, y2, chessPieceArray);
}

//Prints the board
void chess::printBoard() {
	for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				cout << chessPieceArray[i][j].get_pieceColor() << " ";
			}
			cout << endl;
		}
}