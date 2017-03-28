#include <iostream>
using namespace std;
#include <string>

class ChessGUI{
private:
public:
  ChessGUI();
  void printChessGUI(chessPiece** myBoardToDraw);
  void welcomeToChess();
  void printBorder();
};
ChessGUI::ChessGUI() {
  welcomeToChess();
}
void ChessGUI::printChessGUI(chessPiece** myBoardToDraw) {

  bool printStar = false;
  /*
    Generate ASCII Text Chess Board,
    Load Piece Color/Type for pieces on the board
  */
  int num = 0;
  char lettersToUse[8] = {'A','B','C','D','E','F','G','H'};
  cout << "\t     ";
  for(int jj=0; jj < 64; jj++) {
    if(jj%8 == 3) {
      cout << lettersToUse[num];
      num++;
    } else {
      cout << " ";
    }
  }
  cout <<"\n";

  cout << "\t";
  printBorder();
  cout << "\n";

  int row = 0, col = 0;
  num = 1;
  for(int jj=1; jj<41; jj++) {
    if(jj % 5 == 3) {
      cout << "   " << num;
      num++;
    }
    cout << "\t|    ";
    for(int ii=0; ii<64; ii++) {
      if(ii%8 == 0) {
        printStar = !printStar;
      }
      switch (ii%8) {
        case 3:
        switch(jj%5) {
          case 0:
          case 1:
          if(printStar) {

            cout << "*";
          } else {
            cout << " ";
          }
            break;
          case 3:
          //Character Color
           if(myBoardToDraw[row][col].get_pieceColor() != '*') {
             cout << myBoardToDraw[row][col].get_pieceColor();
           } else {
             if(printStar) {

               cout << "*";
             } else {
               cout << " ";
             }
           }
          break;
          default:
          if(printStar) {

            cout << "*";
          } else {
            cout << " ";
          }
          break;
        }
        break;
        case 4:
        switch(jj%5) {
          case 0:
          case 1:
          if(printStar) {

            cout << "*";
          } else {
            cout << " ";
          }
            break;
          case 3:
          //Character Type
          if(myBoardToDraw[row][col].get_pieceType() != '*') {
            cout << myBoardToDraw[row][col].get_pieceType();
          } else {
            if(printStar) {

              cout << "*";
            } else {
              cout << " ";
            }
          }
          col++;
          if(col > 7){
            col = 0;
            row++;
          }
          break;
          default:
          if(printStar) {

            cout << "*";
          } else {
            cout << " ";
          }
          break;
        }
        break;
        default:
          if(printStar) {

            cout << "*";
          } else {
            cout << " ";
          }
          break;
      }
    }
    cout << "    |\n";
    if(jj%5 == 0) {
      printStar = !printStar;
    }
  }
  cout << "\t";
  printBorder();
  cout << "\n";
}
void ChessGUI::welcomeToChess() {
  cout <<"\n\n\n\t         ▄▄                   ▄▄  \n";
  cout <<"\t          ▀█                   ▀█ \n";
  cout <<"\t          ▄█                   ▄█   ██████   ███   ███   ██████   ██████    ██████\n";
  cout <<"\t  █████████▀           █████████▀   ██████   ███   ███   ███      ███       ███\n";
  cout <<"\t   ▄██████▄             ▄██████▄    ███      █████████   ███      ███       ███\n";
  cout <<"\t ▄██▀    ▀██▄         ▄██▀    ▀██▄  ███      █████████   ██████   ██████    ██████ \n";
  cout <<"\t ██        ██         ██        ██  ███      █████████   ███         ███       ███\n";
  cout <<"\t ██   ██   ██         ██   ██   ██  ██████   ███   ███   ███         ███       ███\n";
  cout <<"\t ██        ██         ██        ██  ██████   ███   ███   ██████   ██████    ██████\n";
  cout <<"\t  ██▄    ▄██           ██▄    ▄██ \n";
  cout <<"\t   ▀██████▀             ▀██████▀  \n";
  cout <<"\t                                  \n";
  cout <<"\t                                  \n";
  cout <<"\t           █████████████          \n";
  cout <<"\t                                  \n";
  cout <<"\t                                  \n";
}
void ChessGUI::printBorder() {
  cout << " ";
  for(int ii=0; ii<71; ii++) {
    cout << "-";
  }
  cout << " ";
}
