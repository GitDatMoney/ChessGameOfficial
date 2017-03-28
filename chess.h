
//chess.h

#include <iostream>
#include <sstream>
#include <string>
#include "tutorials.h"
#include "tutorials.cpp"
#include "chessPiece.cpp"

using namespace std;

class chess {
private:
  chessPiece** chessPieceArray;
  chessPiece** tempBoard;
  string whiteMoves;
  string blackMoves;
public:
  chess();
  chessPiece** getBoard();
  void setupBoard();
  void move(int x1, int y1, int x2, int y2);
  void getAllMoves(char color);
  string getWhiteMoves();
  string getBlackMoves();
  bool searchForMove(int x1, int y1, int x2, int y2, char c);
  bool move(int x1, int y1, int x2, int y2, char c);
  void printBoard();
};