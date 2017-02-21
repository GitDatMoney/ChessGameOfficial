//chess.h
#include <iostream>

using namespace std;
#include "chessPiece.h"

//Class that contains the "board" which holds all the chessPiece objects
class chess {

private:
	chessPiece* chessPieceArray[8][8];

public:
	chess()
};

chess::chess() {
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			chessPieceArray[i][j] = new Pawn('W');
			break;
		}
	}
}