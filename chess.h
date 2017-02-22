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
		void move(int x1, int y1, int x2, int y2);
	 }
	 void setupBoard() {
		 //Add all pieces to a new board
		 for(int i = 0; i < 8; i++){
			 			chessPieceArray[1][i] = new Pawn('b');
						chessPieceArray[6][i] = new Pawn('w');
		 	}
			for(int i = 2; i < 6; i++){
				for(int j = 0; j < 8; j++){
					chessPieceArray[i][j] = new NullPiece('*');
				}
			}
			chessPieceArray[0][0] = new Rook('b');
			chessPieceArray[0][1] = new Knight('b');
			chessPieceArray[0][2] = new Bishop('b');
			chessPieceArray[0][3] = new King('b');
			chessPieceArray[0][4] = new Queen('b');
			chessPieceArray[0][5] = new Bishop('b');
			chessPieceArray[0][6] = new Knight('b');
			chessPieceArray[0][7] = new Rook('b');

			chessPieceArray[7][0] = new Rook('w');
			chessPieceArray[7][1] = new Knight('w');
			chessPieceArray[7][2] = new Bishop('w');
			chessPieceArray[7][4] = new King('w');
			chessPieceArray[7][3] = new Queen('w');
			chessPieceArray[7][5] = new Bishop('w');
			chessPieceArray[7][6] = new Knight('w');
			chessPieceArray[7][7] = new Rook('w');

			//Draw the Board to Console
			cout << "     A:   B:   C:   E:   F:   G:   H:   I:\n" << endl;
			for(int i = 0; i < 8; i++){
				cout << i+1 << ": ";
						 for(int j = 0; j < 8; j++){
							 cout << "  " << chessPieceArray[i][j]->get_pieceType() << "  ";
						 }
						 cout << "\n" << endl;
			 }
	 }
	 void chess::move(int x1, int y1, int x2, int y2) {
		 chessPieceArray[x1][y1].pieceMove(x2, y2, chessPieceArray);
		}
};
