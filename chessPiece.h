//chessPiece.h
#include <sstream>
//Defines the basic parameters of all chessPiece objects
class chessPiece {

public:
	virtual bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	char get_pieceType();
	char get_pieceColor();
	virtual string getMoves(int x1, int y1, chessPiece** chessPieceArray);
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

string chessPiece::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	stringstream moves;
	if (this->pieceType == '*')
	{
		return "";
	}
	else if (this->pieceType == 'p')
	{
		if (pieceColor == 'w')
		{
			int i = -1;
			if (x1 == 6)
			{
				if (chessPieceArray[x1-2][y1].get_pieceType() == '*' && chessPieceArray[x1-1][y1].get_pieceType() == '*')
				{
					moves << x1 << y1 << x1-2 << y1 << '*';
				}
			}
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
		else
		{
			int i = -1;
			if (x1 == 1)
			{
				if (chessPieceArray[x1+2][y1].get_pieceType() == '*' && chessPieceArray[x1+1][y1].get_pieceType() == '*')
				{
					moves << x1 << y1 << x1+2 << y1 << '*';
				}
			}
			while (i < 2)
			{
				if (chessPieceArray[x1+1][y1+i].get_pieceType() == '*' && i == 0)
				{
					moves << x1 << y1 << x1-1 << y1+i << '*';
				}
				else if(chessPieceArray[x1+1][y1+i].get_pieceColor() == 'w' && i != 0)
				{
					moves << x1 << y1 << x1-1 << y1+i << chessPieceArray[x1-1][y1+i].get_pieceType();
				}
			i++;
			}
		}
	}
	else if (get_pieceType() == 'r')
	{
		int i = 1;
		while(x1+i < 8 && x1+i >=0 && (chessPieceArray[x1+i][y1].get_pieceType() == '*'|| chessPieceArray[x1+i][y1].get_pieceColor() != this->get_pieceColor()))
		{
			if (chessPieceArray[x1+i][y1].get_pieceType() != '*')
			{
				moves << x1 << y1 << x1+i << y1 << chessPieceArray[x1+i][y1].get_pieceType();
				i = 10;
			}
			else{
				moves << x1 << y1 << x1+i << y1 << '*';
			}
			i++;
		}
		i = 1;
		while(x1-i < 8 && x1-i >=0 && (chessPieceArray[x1-i][y1].get_pieceType() == '*'|| chessPieceArray[x1-i][y1].get_pieceColor() != this->get_pieceColor()))
		{
			if (chessPieceArray[x1-i][y1].get_pieceType() != '*')
			{
				moves << x1 << y1 << x1-i << y1 << chessPieceArray[x1-i][y1].get_pieceType();
				i = 10;
			}
			else{
				moves << x1 << y1 << x1-i << y1 << '*';
			}
			i++;
		}
		i = 1;
		while(y1-i < 8 && y1-i >=0 && (chessPieceArray[x1][y1-i].get_pieceType() == '*'|| chessPieceArray[x1][y1-i].get_pieceColor() != this->get_pieceColor()))
		{
			if (chessPieceArray[x1][y1+i].get_pieceType() != '*')
			{
				moves << x1 << y1 << x1 << y1-i << chessPieceArray[x1][y1-i].get_pieceType();
				i = 10;
			}
			else{
				moves << x1 << y1 << x1 << y1-i << '*';
			}
			i++;
		}
				i = 1;
		while(y1+i < 8 && y1+i >=0 && (chessPieceArray[x1][y1+i].get_pieceType() == '*'|| chessPieceArray[x1][y1+i].get_pieceColor() != this->get_pieceColor()))
		{
			if (chessPieceArray[x1][y1+i].get_pieceType() != '*')
			{
				moves << x1 << y1 << x1 << y1+i << chessPieceArray[x1][y1+i].get_pieceType();
				i = 10;
			}
			else{
				moves << x1 << y1 << x1 << y1+i << '*';
			}
			i++;
		}
	}
	else if (get_pieceType() == 'k')
	{
		if (x1+1 < 8 && y1+2 < 8)
		{
			if (chessPieceArray[x1+1][y1+2].get_pieceType() == '*' || chessPieceArray[x1+1][y1+2].get_pieceColor() != this->get_pieceColor())
			{
				moves << x1 << y1 << x1+1 << y1+2 << chessPieceArray[x1+1][y1+2].get_pieceType();
			}
		}
		if (x1-1>=0 && y1+2 < 8)
		{		
			if (chessPieceArray[x1-1][y1+2].get_pieceType() == '*' || chessPieceArray[x1-1][y1+2].get_pieceColor() != this->get_pieceColor())
			{
				moves << x1 << y1 << x1-1 << y1+2 << chessPieceArray[x1-1][y1+2].get_pieceType();
			}
		}
		if (x1+1 < 8 && y1-2 >= 0)
		{
			if (chessPieceArray[x1+1][y1-2].get_pieceType() == '*' || chessPieceArray[x1+1][y1-2].get_pieceColor() != this->get_pieceColor())
			{
				moves << x1 << y1 << x1+1 << y1-2 << chessPieceArray[x1+1][y1-2].get_pieceType();
			}
		}
		if (x1-1 >= 0 && y1-2 >= 0)
		{		
			if (chessPieceArray[x1-1][y1-2].get_pieceType() == '*' || chessPieceArray[x1-1][y1-2].get_pieceColor() != this->get_pieceColor())
			{
				moves << x1 << y1 << x1-1 << y1-2 << chessPieceArray[x1-1][y1-2].get_pieceType();
			}
		}
		if (x1+2 < 8 && y1+1 < 8)
		{
			if (chessPieceArray[x1+2][y1+1].get_pieceType() == '*' || chessPieceArray[x1+2][y1+1].get_pieceColor() != this->get_pieceColor())
			{
				moves << x1 << y1 << x1+2 << y1+1 << chessPieceArray[x1+2][y1+1].get_pieceType();
			}
		}
		if (x1+2 < 8 && y1-1 >=0)
		{
			if (chessPieceArray[x1+2][y1-1].get_pieceType() == '*' || chessPieceArray[x1+2][y1-1].get_pieceColor() != this->get_pieceColor())
			{
				moves << x1 << y1 << x1+2 << y1-1 << chessPieceArray[x1+2][y1-1].get_pieceType();
			}
		}
		if (x1-2 >= 0 && y1+1 < 8)
		{
			if (chessPieceArray[x1-2][y1+1].get_pieceType() == '*' || chessPieceArray[x1-2][y1+1].get_pieceColor() != this->get_pieceColor())
			{
				moves << x1 << y1 << x1-2 << y1+1 << chessPieceArray[x1-2][y1+1].get_pieceType();
			}
		}
		if (x1-2 >=0 && y1-1 >=0)
		{
			if (chessPieceArray[x1-2][y1-1].get_pieceType() == '*' || chessPieceArray[x1-2][y1-1].get_pieceColor() != this->get_pieceColor())
			{
				moves << x1 << y1 << x1-2 << y1-1 << chessPieceArray[x1-2][y1-1].get_pieceType();
			}
		}
	}
	else if (get_pieceType() == 'b')
	{
		int i = 1;
		while (x1+i < 8 && y1+i < 8)
		{
			if (chessPieceArray[x1+i][y1+i].get_pieceType() == '*' ||chessPieceArray[x1+i][y1+i].get_pieceColor() != this->get_pieceColor()) 
			{
				if(chessPieceArray[x1+i][y1+i].get_pieceType() != '*')
				{
					moves << x1 << y1 << x1+i << y1+i << chessPieceArray[x1+i][y1+i].get_pieceType();
					i = 10;
				}
				else
				{
					moves << x1 << y1 << x1+i << y1+i << "*";
					cout << "1!"  << x1 << y1 << x1+i << y1+i << endl;
					i += 1;
				}
			}
			else
			{
				i = 10;
			}
		}
		i = 1;
		while (x1+i < 8 && y1-i >= 0)
		{
			if (chessPieceArray[x1+i][y1-i].get_pieceType() == '*' ||chessPieceArray[x1+i][y1-i].get_pieceColor() != this->get_pieceColor()) 
			{
				if(chessPieceArray[x1+i][y1-i].get_pieceType() != '*')
				{
					moves << x1 << y1 << x1+i << y1-i << chessPieceArray[x1+i][y1-i].get_pieceType();
					i = 10;
				}
				else
				{
					moves << x1 << y1 << x1+i << y1-i << "*";
					cout << "2"  << x1 << y1 << x1+i << y1-i << endl;
					i += 1;
				}
			}
			else
			{
				i = 10;
			}
		}
		i = 1;
		while (x1-i > 0 && y1-i >= 0)
		{
			if (chessPieceArray[x1-i][y1-i].get_pieceType() == '*' ||chessPieceArray[x1-i][y1-i].get_pieceColor() != this->get_pieceColor()) 
			{
				if(chessPieceArray[x1-i][y1-i].get_pieceType() != '*')
				{

					moves << x1 << y1 << x1-i << y1-i << chessPieceArray[x1-i][y1-i].get_pieceType();
					i = 10;
				}
				else
				{
					moves << x1 << y1 << x1-i << y1-i << "*";
					cout << "3"  << x1 << y1 << x1-i << y1-i << endl;
					i += 1;
				}
			}
			else
			{
				i = 10;
			}

		}
		i = 1;
		while (x1-i >= 0 && y1+i < 8)
		{
			if (chessPieceArray[x1-i][y1+i].get_pieceType() == '*' ||chessPieceArray[x1-i][y1+i].get_pieceColor() != this->get_pieceColor()) 
			{
				if(chessPieceArray[x1-i][y1+i].get_pieceType() != '*')
				{
					moves << x1 << y1 << x1-i << y1+i << chessPieceArray[x1-i][y1+i].get_pieceType();
					i = 10;
				}
				else
				{
					moves << x1 << y1 << x1-i << y1+i << "*";
					cout << "4"  << x1 << y1 << x1-i << y1+i << endl;
					i += 1;					
				}
			}
			else
			{
				i = 10;
			}

		}		
	}
	else if (this->get_pieceType() == 'q')
	{
		int i = 1;
		while (x1+i < 8 && y1+i < 8)
		{
			if (chessPieceArray[x1+i][y1+i].get_pieceType() == '*' ||chessPieceArray[x1+i][y1+i].get_pieceColor() != this->get_pieceColor()) 
			{
				if(chessPieceArray[x1+i][y1+i].get_pieceType() != '*')
				{
					moves << x1 << y1 << x1+i << y1+i << chessPieceArray[x1+i][y1+i].get_pieceType();
					i = 10;
				}
				else
				{
					moves << x1 << y1 << x1+i << y1+i << "*";
					i += 1;
				}
			}
			else
			{
				i = 10;
			}

		}
		i = 1;
		while (x1+i < 8 && y1-i >= 0)
		{
			if (chessPieceArray[x1+i][y1-i].get_pieceType() == '*' ||chessPieceArray[x1+i][y1-i].get_pieceColor() != this->get_pieceColor()) 
			{
				if(chessPieceArray[x1+i][y1-i].get_pieceType() != '*')
				{
					moves << x1 << y1 << x1+i << y1-i << chessPieceArray[x1+i][y1-i].get_pieceType();
					i = 10;
				}
				else
				{
					moves << x1 << y1 << x1+i << y1-i << "*";
					i += 1;
				}
			}
			else
			{
				i = 10;
			}
		}
		i = 1;
		while (x1-i > 0 && y1-i >= 0)
		{
			if (chessPieceArray[x1-i][y1-i].get_pieceType() == '*' ||chessPieceArray[x1-i][y1-i].get_pieceColor() != this->get_pieceColor()) 
			{
				if(chessPieceArray[x1-i][y1-i].get_pieceType() != '*')
				{
					cout << x1 << y1 << x1-i << y1-i << endl;
					moves << x1 << y1 << x1-i << y1-i << chessPieceArray[x1-i][y1-i].get_pieceType();
					i = 10;
				}
				else
				{
					moves << x1 << y1 << x1-i << y1-i << "*";
					i += 1;
				}
			}
			else
			{
				i = 10;
			}
		}
		while (x1-i >= 0 && y1+i < 8)
		{
			if (chessPieceArray[x1-i][y1+i].get_pieceType() == '*' ||chessPieceArray[x1-i][y1+i].get_pieceColor() != this->get_pieceColor()) 
			{
				if(chessPieceArray[x1-i][y1+i].get_pieceType() != '*')
				{
					moves << x1 << y1 << x1-i << y1+i << chessPieceArray[x1-i][y1+i].get_pieceType();

					i = 10;
				}
				else
				{
					moves << x1 << y1 << x1-i << y1+i << "*";
					i += 1;
				}
			}
			else
			{
				i = 10;
			}
		}
		i = 1;
		while(x1+i <= 8 && x1+i >=0 && (chessPieceArray[x1+i][y1].get_pieceType() == '*'|| chessPieceArray[x1+i][y1].get_pieceColor() != this->get_pieceColor()))
		{
			if (chessPieceArray[x1+i][y1].get_pieceType() != '*')
			{
				moves << x1 << y1 << x1+i << y1 << chessPieceArray[x1+i][y1].get_pieceType();
				i = 10;
			}
			else{
				moves << x1 << y1 << x1+i << y1 << '*';
			}
			i++;
		}
		i = 1;
		while(x1-i < 8 && x1-i >=0 && (chessPieceArray[x1-i][y1].get_pieceType() == '*'|| chessPieceArray[x1-i][y1].get_pieceColor() != this->get_pieceColor()))
		{
			if (chessPieceArray[x1+i][y1].get_pieceType() != '*')
			{
				moves << x1 << y1 << x1-i << y1 << chessPieceArray[x1-i][y1].get_pieceType();
				i = 10;
			}
			else{
				moves << x1 << y1 << x1-i << y1 << '*';
			}
			i++;
		}
		i = 1;
		while(y1-i < 8 && y1-i >=0 && (chessPieceArray[x1][y1-i].get_pieceType() == '*'|| chessPieceArray[x1][y1-i].get_pieceColor() != this->get_pieceColor()))
		{
			if (chessPieceArray[x1][y1+i].get_pieceType() != '*')
			{
				moves << x1 << y1 << x1 << y1-i << chessPieceArray[x1][y1-i].get_pieceType();
				i = 10;
			}
			else{
				moves << x1 << y1 << x1 << y1-i << '*';
			}
			i++;
		}
				i = 1;
		while(y1+i <= 8 && y1+i >=0 && (chessPieceArray[x1][y1+i].get_pieceType() == '*'|| chessPieceArray[x1][y1+i].get_pieceColor() != this->get_pieceColor()))
		{
			if (chessPieceArray[x1][y1+i].get_pieceType() != '*')
			{
				moves << x1 << y1 << x1 << y1+i << chessPieceArray[x1][y1+i].get_pieceType();
				i = 10;
			}
			else{
				moves << x1 << y1 << x1 << y1+i << '*';
			}
			i++;
		}
	}
	else if (this-> get_pieceType() == 'K') //for king
	{
		for (int i = -1; i < 2; i++ )
		{
			for (int j = -1; j < 2; j++)
			{
				if (x1+i >= 0 && x1 + i < 8 && y1 + j >= 0 && y1 + j < 8)
				{
					if (chessPieceArray[x1+i][y1+j].get_pieceType() == '*' || chessPieceArray[x1+i][y1+j].get_pieceColor() != this->get_pieceColor() && (i != 0 || j !=0))
					{
						moves << x1 << y1 << x1 << y1+i << chessPieceArray[x1+i][y1+j].get_pieceType();
					}
				}
			}
		}
	}
	return moves.str();
}

//Defines A null Piece
class NullPiece: public chessPiece {

public:
	NullPiece(char pieceColor);
	bool pieceMove(int new_xPos, int new_yPos, chessPiece (&chessPieceArray)[8][8]);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
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

string NullPiece::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}
//Defines the Pawn
class Pawn: public chessPiece {

public:
	Pawn(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);};
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

string Pawn::getMoves(int x1, int y1, chessPiece** chessPieceArray)
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
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
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
string Rook::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}

//Defines the Knight
class Knight: public chessPiece {

public:
	Knight(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
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
string Knight::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}

//Defines the Bishop
class Bishop: public chessPiece {

public:
	Bishop(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
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
string Bishop::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}

//Defines the Queen
class Queen: public chessPiece {

public:
	Queen(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
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

string Queen::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}

//Defines the king
class King: public chessPiece {

public:
	King(char pieceColor);
	bool pieceMove(int x1, int y1, int new_xPos, int new_yPos, chessPiece** chessPieceArray);
	string getMoves(int x1, int y1, chessPiece** chessPieceArray);
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
string King::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	
}


























