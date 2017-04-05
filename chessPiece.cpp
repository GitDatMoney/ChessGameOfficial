//chessPiece.cpp

#include "chessPiece.h"

char chessPiece::get_pieceType() {
	return pieceType;
}

char chessPiece::get_pieceColor() {
	return pieceColor;
}

string chessPiece::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
	stringstream moves;
	//There is a null piece, return nothing
	if (this->pieceType == '*')
	{
		return "";
	}
	//Pawn Moves
	else if (this->pieceType == 'p')
	{
		//If white
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
		{//Piece is black
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
					moves << x1 << y1 << x1+1 << y1+i << '*';
				}
				else if(chessPieceArray[x1+1][y1+i].get_pieceColor() == 'w' && i != 0)
				{
					moves << x1 << y1 << x1+1 << y1+i << chessPieceArray[x1-1][y1+i].get_pieceType();
				}
			i++;
			}
		}
	}
	//Rook
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
	//knight
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
	//bishop
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
		i = 1;
		//While the piece is in the range of the board;
		while (x1-i >= 0 && y1+i < 8)
		{//If there is no piece or a piece of the opposite color
			if (chessPieceArray[x1-i][y1+i].get_pieceType() == '*' ||chessPieceArray[x1-i][y1+i].get_pieceColor() != this->get_pieceColor())
			{//Piece ran into another piece
				if(chessPieceArray[x1-i][y1+i].get_pieceType() != '*')
				{//0
					moves << x1 << y1 << x1-i << y1+i << chessPieceArray[x1-i][y1+i].get_pieceType();
					i = 10;
				}
				else
				{//Is a null piece, change the previous place of the piece to a null piece
					moves << x1 << y1 << x1-i << y1+i << "*";
					i += 1;
				}
			}
			else
			{//Either the piece is blocked in, or the move is not valid for some reason
				i = 10;
			}

		}
	}
	//Queen
	else if (this->get_pieceType() == 'q')
	{//Basically the same as a combination of the rook and the Bishop
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
					i += 1;
				}
			}
			else
			{
				i = 10;
			}

		}
		i = 1;
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
	else if (this-> get_pieceType() == 'o') //for king
	{
		if (this->get_pieceColor() == 'w') //this checks for castle
		{
			if (x1 == 7 && y1 == 4 && chessPieceArray[x1][y1+1].get_pieceType() == '*' && chessPieceArray[x1][y1+2].get_pieceType() == '*' && chessPieceArray[x1][y1+3].get_pieceType() == 'r')
			{
				moves << x1 << y1 << 7 << 6 << '%'; //% will flag that it is a castle
			}
			if (x1 == 7 && y1 == 4 && chessPieceArray[x1][y1-1].get_pieceType() == '*' && chessPieceArray[x1][y1-2].get_pieceType() == '*'&& chessPieceArray[x1][y1-3].get_pieceType() == '*' && chessPieceArray[x1][y1-4].get_pieceType() == 'r')
			{
				moves << x1 << y1 << 7 << 1 << '%'; //% will flag that it is a castle
			}
		}
		else //this checks for castle for black king
		{
			if (x1 == 0 && y1 == 4 && chessPieceArray[x1][y1+1].get_pieceType() == '*' && chessPieceArray[x1][y1+2].get_pieceType() == '*'&& chessPieceArray[x1][y1+3].get_pieceType() == '*')
			{
				moves << x1 << y1 << 0 << 6 << '%'; //% will flag that it is a castle
			}
			if (x1 == 0 && y1 == 4 && chessPieceArray[x1][y1-1].get_pieceType() == '*' && chessPieceArray[x1][y1-2].get_pieceType() == '*'&& chessPieceArray[x1][y1-3].get_pieceType() == '*' && chessPieceArray[x1][y1-4].get_pieceType() == 'r')
			{
				moves << x1 << y1 << 0 << 1 << '%'; //% will flag that it is a castle
			}
		}

		for (int i = -1; i < 2; i++ )
		{
			for (int j = -1; j < 2; j++)
			{
				if (x1+i >= 0 && x1 + i < 8 && y1 + j >= 0 && y1 + j < 8)
				{
					if (chessPieceArray[x1+i][y1+j].get_pieceType() == '*' || chessPieceArray[x1+i][y1+j].get_pieceColor() != this->get_pieceColor() && (i != 0 || j !=0))
					{
						moves << x1 << y1 << x1 + i << y1 + j << chessPieceArray[x1+i][y1+j].get_pieceType();
					}
				}
			}
		}
	}
	return moves.str();
}

NullPiece::NullPiece(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = '*';
}
//TODO

string NullPiece::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{

}

Pawn::Pawn(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'p';
}
//TODO
//must be called with x1, y1 as well

string Pawn::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{
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


Rook::Rook(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'r';
}
//TODO

string Rook::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{

}

Knight::Knight(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'k';
}
//TODO

string Knight::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{

}

Bishop::Bishop(char pieceColor) {

	this->pieceColor = pieceColor;
	pieceType = 'b';
}
//TODO

string Bishop::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{

}

Queen::Queen(char pieceColor) {

	this->pieceColor = pieceColor;
	this->pieceType = 'q';
}
//TODO


string Queen::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{

}

King::King(char pieceColor) {

	this->pieceColor = pieceColor;
	this->pieceType = 'o'; //o is king
}
//TODO

string King::getMoves(int x1, int y1, chessPiece** chessPieceArray)
{

}
