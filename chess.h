//chess.h
#include <iostream>

using namespace std;
#include "chessPiece.h"

//Class that contains the "board" which holds all the chessPiece objects

class chess {
private:
	chessPiece** chessPieceArray;
public:
	chess(){
		//Initializes the chessPieceArray
		chessPieceArray = new chessPiece*[8];
		for(int i = 0; i < 8; i++) {
			chessPieceArray[i] = new chessPiece[8];
		}

	}

	void setupBoard() {
		 //Add all pieces to a new board
		 for(int i = 0; i < 8; i++){
			 			chessPieceArray[1][i] = Pawn('b');
						chessPieceArray[6][i] = Pawn('w');
		 	}
			for(int i = 2; i < 6; i++){
				for(int j = 0; j < 8; j++){
					chessPieceArray[i][j] = NullPiece('*');
				}
			}
			chessPieceArray[0][0] = Rook('b');
			chessPieceArray[0][1] = Knight('b');
			chessPieceArray[0][2] = Bishop('b');
			chessPieceArray[0][3] = King('b');
			chessPieceArray[0][4] = Queen('b');
			chessPieceArray[0][5] = Bishop('b');
			chessPieceArray[0][6] = Knight('b');
			chessPieceArray[0][7] = Rook('b');

			chessPieceArray[7][0] = Rook('w');
			chessPieceArray[7][1] = Knight('w');
			chessPieceArray[7][2] = Bishop('w');
			chessPieceArray[7][4] = King('w');
			chessPieceArray[7][3] = Queen('w');
			chessPieceArray[7][5] = Bishop('w');
			chessPieceArray[7][6] = Knight('w');
			chessPieceArray[7][7] = Rook('w');

			//Draw the Board to Console
			cout << "     A:   B:   C:   E:   F:   G:   H:   I:\n" << endl;
			for(int i = 0; i < 8; i++){
				cout << i+1 << ": ";
						 for(int j = 0; j < 8; j++){
							 cout << "  " << chessPieceArray[i][j].get_pieceType() << "  ";
						 }
						 cout << "\n" << endl;
			 }
	 }
	void move(int x1, int y1, int x2, int y2) {
		 chessPieceArray[x1][y1].pieceMove(x2, y2, chessPieceArray);
	}
};
