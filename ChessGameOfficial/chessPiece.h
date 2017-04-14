
//chessPiece.h
#include <sstream>
#include <iostream>
using namespace std;
#include <string>
//Defines the basic parameters of all chessPiece objects
class chessPiece {

public:
	//Abstract piece move inherited by all types of pieces
	char get_pieceType();
	char get_pieceColor();
	//Gets all possible moves relative to the x1,y1 input from the user based on the board passed in
	virtual string getMoves(int x1, int y1, chessPiece** chessPieceArray);

protected:
	//Data fields belonging to each piece
	char pieceColor;
	char pieceType;
};

//Defines A null Piece
class NullPiece: public chessPiece {

public:
	NullPiece(char pieceColor);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

//Defines the Pawn
class Pawn: public chessPiece {

public:
	Pawn(char pieceColor);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

//Defines the the Rook
class Rook: public chessPiece {

public:
	Rook(char pieceColor);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

//Defines the Knight
class Knight: public chessPiece {

public:
	Knight(char pieceColor);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

//Defines the Bishop
class Bishop: public chessPiece {

public:
	Bishop(char pieceColor);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

//Defines the Queen
class Queen: public chessPiece {

public:
	Queen(char pieceColor);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

//Defines the king
class King: public chessPiece {

public:
	King(char pieceColor);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
};