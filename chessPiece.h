//chessPiece.h
#include <sstream>
//Defines the basic parameters of all chessPiece objects
class chessPiece {

public:
	virtual bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	char get_pieceType();
	char get_pieceColor();
	stringstream* getMoves(int x1, int y1, chessPiece** chessPieceArray);
	void statusPrint();

protected:
	char pieceColor;
	char pieceType;
};

char chessPiece::get_pieceType() {
	return pieceType;
}

char chessPiece::get_pieceColor() {
	return pieceColor;
}

bool chessPiece::pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray) {

}

stringstream* chessPiece::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	cout << "chessPiece moves" << endl;
}

//Defines A null Piece
class NullPiece: public chessPiece {

public:
	NullPiece(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);
	stringstream* getMoves(int x1, int y1, chessPiece** chessPieceArray);
};
NullPiece::NullPiece(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = '*';
}
//TODO
bool NullPiece::pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]) {

	if(pieceColor == 'w') {

	}
	else
	{

	}

}

stringstream* NullPiece::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}
//Defines the Pawn
class Pawn: public chessPiece {

public:
	Pawn(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	stringstream* getMoves(int x1, int y1, chessPiece** chessPieceArray);};
Pawn::Pawn(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'p';
}
//TODO
//must be called with x1, y1 as well
bool Pawn::pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray) {

	if(new_xPos > 8 || new_yPos > 8){
		cout << "Error Invalid Move!" << endl;
		return false;
	}
	return true;
}

stringstream* Pawn::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	cout << "Pawn moves" << endl;
	stringstream moves;
	if (pieceColor == 'w')
	{
		int i = -1;
		while (i < 2)
		{
			if (chessPieceArray[x1-1][y1+i].get_pieceType() == '*' && i == 0)
			{
				moves << x1 << y1 << x1-1 << y1+i << '*';
			}
			else if(chessPieceArray[x1-1][y1+i].get_pieceColor() == 'b' && i != 0)
			{
				moves << x1 << y1 << x1-1 << y1+i << chessPieceArray[x1-1][y1+i].get_pieceType();
			}
		i++;
		}
	}

}

//Defines the the Rook
class Rook: public chessPiece {

public:
	Rook(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	stringstream* getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

Rook::Rook(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'r';
}
//TODO
bool Rook::pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
	if(new_xPos > 8 || new_yPos > 8){
		cout << "Error Invalid Move!" << endl;
		return false;
	}
}
stringstream* Rook::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}

//Defines the Knight
class Knight: public chessPiece {

public:
	Knight(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	stringstream* getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

Knight::Knight(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'k';
}
//TODO
bool Knight::pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
	if(new_xPos > 8 || new_yPos > 8){
		cout << "Error Invalid Move!" << endl;
		return false;
	}
}
stringstream* Knight::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}

//Defines the Bishop
class Bishop: public chessPiece {

public:
	Bishop(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	stringstream* getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

Bishop::Bishop(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'b';
}
//TODO
bool Bishop::pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
	if(new_xPos > 8 || new_yPos > 8){
		cout << "Error Invalid Move!" << endl;
		return false;
	}
}
stringstream* Bishop::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}

//Defines the Queen
class Queen: public chessPiece {

public:
	Queen(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	stringstream* getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

Queen::Queen(char pieceType) {

	this->pieceColor = pieceColor;
	pieceType = 'q';
}
//TODO
bool Queen::pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
	if(new_xPos > 8 || new_yPos > 8){
		cout << "Error Invalid Move!" << endl;
		return false;
	}
}

stringstream* Queen::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}

//Defines the king
class King: public chessPiece {

public:
	King(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	stringstream* getMoves(int x1, int y1, chessPiece** chessPieceArray);
};

King::King(char pieceType) {

	this->pieceColor = pieceColor;
	pieceType = 'q';
}
//TODO
bool King::pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
	if(new_xPos > 8 || new_yPos > 8){
		cout << "Error Invalid Move!" << endl;
		return false;
	}
}
stringstream* King::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}
