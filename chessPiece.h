//chessPiece.h

//Defines the basic parameters of all chessPiece objects
class chessPiece {

public:
	virtual bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);
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

//Defines the characteristics of the pawn
class Pawn: public chessPiece {

public:
	Pawn(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);

};

Pawn::Pawn(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'p';
}
//TODO
bool Pawn::pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]) {

	if(pieceColor == 'w') {

	}
	else
	{

	}

}

class Rook: public chessPiece {

public:
	Rook(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);

};

Rook::Rook(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'r';
}
//TODO
bool Rook::pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]) {

}

class Knight: public chessPiece {

public:
	Knight(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);

};

Knight::Knight(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'k';
}
//TODO
bool Knight::pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]) {

}

class Bishop: public chessPiece {

public:
	Bishop(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);

};

Bishop::Bishop(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'b';
}
//TODO
bool Bishop::pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]) {

}

class Queen: public chessPiece {

public:
	Queen(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);

};

Queen::Queen(char pieceType) {

	this->pieceColor = pieceColor;
	pieceType = 'q';
}