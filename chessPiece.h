//chessPiece.h

//Defines the basic parameters of all chessPiece objects
class chessPiece {

public:
	virtual bool pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray);
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

bool chessPiece::pieceMove(int new_xPos, int new_yPos, chessPiece** chessPieceArray) {

}
//Defines A null Piece
class NullPiece: public chessPiece {

public:
	NullPiece(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);

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
//Defines the Pawn
class Pawn: public chessPiece {

public:
	Pawn(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);

};
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
	if(pieceColor == 'w') {
		if (y1 == 6)
		{
			int i = 1;
			while (chessPieceArray[y1-i][x1] == NullPiece('*')
			{

			}
		}
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
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);

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

//Defines the Knight
class Knight: public chessPiece {

public:
	Knight(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);

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

//Defines the Bishop
class Bishop: public chessPiece {

public:
	Bishop(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);

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

//Defines the Queen
class Queen: public chessPiece {

public:
	Queen(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);

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

//Defines the king
class King: public chessPiece {

public:
	King(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);

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
