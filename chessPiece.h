
//chessPiece.h

//Defines the basic parameters of all chessPiece objects
class chessPiece {

public:
<<<<<<< HEAD
	virtual bool pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]);
=======
	virtual bool pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray);
>>>>>>> origin/master
	char get_pieceType();
	char get_pieceColor();
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

<<<<<<< HEAD
bool chessPiece::pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]) {
	if(new_xPos > 8){
		cout << "Invalid Position" << endl;
		return false;
	} else {
		cout << "Valid Move";
	}
	return true;
}
//Defines A null Piece
class NullPiece: public chessPiece {
=======
bool chessPiece::pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
>>>>>>> origin/master

public:
	NullPiece(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]);

};
NullPiece::NullPiece(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = '*';
}
//TODO
bool NullPiece::pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]) {

	if(pieceColor == 'w') {

	}
	else
	{

	}

}
//Defines the Pawn
class Pawn: public chessPiece {

public:
	Pawn(char pieceColor);
<<<<<<< HEAD
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]);
=======
	bool pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray);
>>>>>>> origin/master

};
Pawn::Pawn(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'p';
}
//TODO
<<<<<<< HEAD
bool Pawn::pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]) {
=======
bool Pawn::pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
>>>>>>> origin/master

	if(new_xPos >= new_yPos > 8){
		cout << "Error Invalid Move!" << endl;
		return false;
	}
	if(pieceColor == 'w') {

	}
	else
	{

	}
	return true;
}

//Defines the the Rook
class Rook: public chessPiece {

public:
	Rook(char pieceColor);
<<<<<<< HEAD
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]);
=======
	bool pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray);
>>>>>>> origin/master

};

Rook::Rook(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'r';
}
//TODO
<<<<<<< HEAD
bool Rook::pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]) {
=======
bool Rook::pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
>>>>>>> origin/master

}

//Defines the Knight
class Knight: public chessPiece {

public:
	Knight(char pieceColor);
<<<<<<< HEAD
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]);
=======
	bool pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray);
>>>>>>> origin/master

};

Knight::Knight(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'k';
}
//TODO
<<<<<<< HEAD
bool Knight::pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]) {
=======
bool Knight::pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
>>>>>>> origin/master

}

//Defines the Bishop
class Bishop: public chessPiece {

public:
	Bishop(char pieceColor);
<<<<<<< HEAD
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]);
=======
	bool pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray);
>>>>>>> origin/master

};

Bishop::Bishop(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'b';
}
//TODO
<<<<<<< HEAD
bool Bishop::pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]) {
=======
bool Bishop::pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
>>>>>>> origin/master

}

//Defines the Queen
class Queen: public chessPiece {

public:
	Queen(char pieceColor);
<<<<<<< HEAD
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]);
=======
	bool pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray);
>>>>>>> origin/master

};

Queen::Queen(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'Q';
}
//TODO
<<<<<<< HEAD
bool Queen::pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]) {
=======
bool Queen::pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
>>>>>>> origin/master

}

//Defines the king
class King: public chessPiece {

public:
	King(char pieceColor);
<<<<<<< HEAD
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]);
=======
	bool pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray);
>>>>>>> origin/master

};

King::King(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'K';
}
//TODO
<<<<<<< HEAD
bool King::pieceMove(int new_xPos, int new_yPos, chessPiece (chessPieceArray)[8][8]) {
=======
bool King::pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray) {
>>>>>>> origin/master

}