#include <iostream>
using namespace std;
#include <string>

class ChessGUI{
private:
public:
  ChessGUI();
  void printChessGUI();
  void welcomeToChess();
  void printBorder();
};
ChessGUI::ChessGUI() {
  welcomeToChess();
}
void ChessGUI::printChessGUI() {
  bool printStar = false;

  /*
    Generate ASCII Text Chess Board,
    Load Piece Color/Type for pieces on the board
  */
  string myArray[8][8];
  for(int ii=0; ii < 8; ii++) {
    for(int jj=0; jj < 8; jj++) {
      if(ii == 1) {
        myArray[ii][jj] = "p";
      } else if(ii == 6) {
        myArray[ii][jj] = "p";
      } else {
        myArray[ii][jj] = " ";
      }
    }
  }
  cout << "\t";
  printBorder();
  cout << "\n";

  for(int jj=1; jj<41; jj++) {
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
           cout <<"W";
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
           cout <<"p";
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
