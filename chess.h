//chess.h
#include <iostream>

using namespace std;
#include "chessPiece.h"

//Class that contains the "board" which holds all the chessPiece objects
class chess {

private:
	chessPiece chessPieceArray[8][8];

public:
	chess(){
	      cout << "In the Constructor\n";
	    }
};
