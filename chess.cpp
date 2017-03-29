
//chess.cpp

#include "chess.h"

//Regular Functions
void checkCols(string &tempX1)
{

  while(!(tempX1.compare("A") == 0 || tempX1.compare("B") == 0 || tempX1.compare("C") == 0 || tempX1.compare("D") == 0  || tempX1.compare("E") == 0 || tempX1.compare("F") == 0 || tempX1.compare("G") == 0 || tempX1.compare("H") == 0))
  {
    cout << "Mah dawg, you think you l33t, well I am LEET3R" << endl;
    cout << "So plz enter a valid column yo: " ;
    cin >> tempX1;
  }

}

//void checkRows(int )

chess::chess(){
    //Initializes the chessPieceArray
    chessPieceArray = new chessPiece*[8];
    for(int i = 0; i < 8; i++) {
      chessPieceArray[i] = new chessPiece[8];
    }
    whiteMoves = "";
    blackMoves = "";

  }

  chessPiece** chess::getBoard()
  {
    return chessPieceArray;
  }

void chess::setupBoard() {
 //Add all pieces to a new board
 for(int i = 0; i < 8; i++){
        chessPieceArray[1][i] = Pawn('b');
        chessPieceArray[6][i] = Pawn('w');
  }
  for(int i = 2; i < 6; i++){
    for(int j = 0; j < 8; j++){
      chessPieceArray[i][j] = NullPiece('*');
    }
  }
  chessPieceArray[0][0] = Rook('b');
  chessPieceArray[0][1] = Knight('b');
  chessPieceArray[0][2] = Bishop('b');
  chessPieceArray[0][3] = Queen('b');
  chessPieceArray[0][4] = King('b');
  chessPieceArray[0][5] = Bishop('b');
  chessPieceArray[0][6] = Knight('b');
  chessPieceArray[0][7] = Rook('b');

  chessPieceArray[7][0] = Rook('w');
  chessPieceArray[7][1] = Knight('w');
  chessPieceArray[7][2] = Bishop('w');
  chessPieceArray[7][3] = Queen('w');
  chessPieceArray[7][4] = King('w');
  chessPieceArray[7][5] = Bishop('w');
  chessPieceArray[7][6] = Knight('w');
  chessPieceArray[7][7] = Rook('w');

  //Draw the Board to Console

  printBoard();
}

void chess::move(int x1, int y1, int x2, int y2)
 {
  bool validMove = true;
  if ( x1 > 8 || x1 < 0 || y1 > 8 || y1 < 0 ) {
    cout << "Invalid Starting position, Please Choose Another." << endl;
    validMove = false;
  }
  if ( x2 > 8 || x2 < 0 || y2 > 8 || y2 < 0 ) {
    cout << "Invalid Ending position, Please Choose Another." << endl;
    validMove = false;

  }
}


void chess::getAllMoves(char color)
{
string moves = "";
for (int i = 0; i < 8; i++)
{
  for (int j = 0; j < 8; j++)
  {
    if (chessPieceArray[i][j].get_pieceColor() == color)
    {
      moves.append(chessPieceArray[i][j].getMoves(i,j,chessPieceArray));
    }
  }
}
if (color == 'w')
{
  this->whiteMoves = moves;
}
else
{
  this->blackMoves = moves;
}
}

string chess::getWhiteMoves()
{
return this->whiteMoves;
}

string chess::getBlackMoves()
{
  return this->blackMoves;
}

bool chess::searchForMove(int x1, int y1, int x2, int y2, char c)
{
  stringstream s;
  s << x1 << y1 << x2 << y2;
  string pMove = s.str();
  if(c == 'w')
  {
    bool exists = this->whiteMoves.find(pMove) != string::npos;
	cout << whiteMoves.find(pMove) << endl;
	cout << whiteMoves.at(whiteMoves.find(pMove)+4)<< endl;
	if (whiteMoves.at(whiteMoves.find(pMove) + 4) == '%')
	{
		cout << "Castle!" << endl;
	}
    return exists;
  }
  else
  {
    bool exists = this->blackMoves.find(pMove) != string::npos;
    return exists;
  }
}

bool chess::move(int x1, int y1, int x2, int y2, char c)
{
  chessPiece temp = chessPieceArray[x2][y2];
  chessPieceArray[x2][y2] = chessPieceArray[x1][y1];
  chessPieceArray[x1][y1] = NullPiece('*');
  if (c == 'w')
  {
    this->getBlackMoves();
    if (this->blackMoves.find('o') != string::npos)
    {
      cout << "Puts King in danger" << endl;
      chessPieceArray[x1][y1] = chessPieceArray[x2][y2];
      chessPieceArray[x2][y2] = temp;
      return false;
    }
  }
  else{
    this->getWhiteMoves();
    if (this->whiteMoves.find('o') != string::npos)
    {
      chessPieceArray[x1][y1] = chessPieceArray[x2][y2];
      chessPieceArray[x2][y2] = temp;
      return false;
    }
  }
  return true;
}

void chess::printBoard()
{
    cout << endl << "     A:   B:   C:   D:   E:   F:   G:   H:\n" << endl;
    for(int i = 0; i < 8; i++){
      cout << i+1 << ": ";
           for(int j = 0; j < 8; j++){
             cout << "  " << chessPieceArray[i][j].get_pieceType() << "  ";
           }
           cout << "\n" << endl;
     }
}