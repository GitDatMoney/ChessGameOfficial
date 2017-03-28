
//main.cpp
//Chess Initial Files
#include "chess.cpp"
#include <exception>
#include <iostream>
#include "chessGui.cpp"
using namespace std;


// this is called when the user selects option 3 (tutorials) in the main menu



int main() {
	ChessGUI theGui;
	int selection = 0;
	cout << "Welcome To Chess" << endl;
	chess* theBoard = new chess();


	while(true) {
		cout << "Please Select A Menu Option: " << endl;
		cout << "1) Quick Play\n2) Custom Match\n3) Tutorials\n4) Options\n5) Exit" << endl;
		cin >> selection;
		int x1,x2,y1,y2;
		char x1C, x2C;
    string tempX1, tempX2;
		switch(selection) {
			case 1:
				cout << "Beginning Game: \n\n" << endl;
				theBoard->setupBoard();
				theGui.printChessGUI(theBoard->getBoard());
				while(true)
				{
					theBoard->getAllMoves('w');
					bool gettingMove = true;
					cout << "White's turn" << endl;
					while(gettingMove)
					{
						cout << "Inital Column: ";
            cin >> tempX1;

            checkCols(tempX1);

            x1C = tempX1[0];

            //checkCol(x1C);
            //checkCol(x1C);
						x1 = (int)x1C - 64;  //Converts character to int, need to add bound checking mechanism and make it case insensitive

						cout << "Inital Row: ";
						cin >> y1;

            while(cin.fail() || y1 < 1 || y1 > 8)
            {
              if(cin.fail())
              {
                cout << "Bruh, learn how to chess... the ROW is a NUMBER, please enter a new one: " << endl;
              }
              else {
                cout <<"Number entered is not in range 1 to 8. Enter new row value:";
              }
              cin.clear();
              cin.ignore(1000,'\n');

              cin >> y1;
            }

            //checkRow(y1);

						cout << "Ending Column: ";
						cin >> tempX2;
            checkCols(tempX2);
            x2C = tempX2[0];

						x2 = (int)x2C - 64;

						cout << "Ending Row: ";
						cin >> y2;
            while(cin.fail() || y2 < 1 || y2 > 8)
            {
              if(cin.fail())
              {
                cout << "Bruh, learn how to chess... the ROW is a NUMBER, please enter a new one: " << endl;
              }
              else {
                cout <<"Number entered is not in range 1 to 8. Enter new row value:";
              }
              cin.clear();
              cin.ignore(1000,'\n');

              cin >> y2;
            }

						if(theBoard->searchForMove(y1-1,x1-1,y2-1,x2-1,'w'))
						{
							if (theBoard->move(y1-1,x1-1,y2-1,x2-1,'w'))
							{
								theGui.printChessGUI(theBoard->getBoard());
								gettingMove = false;
							}
						}
					}
					gettingMove = true;
					cout << "Black's turn" << endl;
					theBoard->getAllMoves('b');
          while(gettingMove)
					{
						cout << "Inital Column: ";
            cin >> tempX1;

            checkCols(tempX1);

            x1C = tempX1[0];

            //checkCol(x1C);
            //checkCol(x1C);
						x1 = (int)x1C - 64;  //Converts character to int, need to add bound checking mechanism and make it case insensitive

						cout << "Inital Row: ";
						cin >> y1;

            while(cin.fail() || y1 < 1 || y1 > 8)
            {
              if(cin.fail())
              {
                cout << "Bruh, learn how to chess... the ROW is a NUMBER, please enter a new one: " << endl;
              }
              else {
                cout <<"Number entered is not in range 1 to 8. Enter new row value:";
              }
              cin.clear();
              cin.ignore(1000,'\n');

              cin >> y1;
            }

            //checkRow(y1);

						cout << "Ending Column: ";
						cin >> tempX2;
            checkCols(tempX2);
            x2C = tempX2[0];

						x2 = (int)x2C - 64;

						cout << "Ending Row: ";
						cin >> y2;
            while(cin.fail() || y2 < 1 || y2 > 8)
            {
              if(cin.fail())
              {
                cout << "Bruh, learn how to chess... the ROW is a NUMBER, please enter a new one: " << endl;
              }
              else {
                cout <<"Number entered is not in range 1 to 8. Enter new row value:";
              }
              cin.clear();
              cin.ignore(1000,'\n');

              cin >> y2;
            }

						if(theBoard->searchForMove(y1-1,x1-1,y2-1,x2-1,'b'))
						{
							if (theBoard->move(y1-1,x1-1,y2-1,x2-1,'b'))
							{
								theGui.printChessGUI(theBoard->getBoard());
								gettingMove = false;
							}
						}
					}
				}

				//x1, y1 are starting position:x2,y2 are ending position
				theBoard->move(x1,y1,x2,y2);
			break;

			case 2:
			break;

			case 3:
			    tutorials();
			break;

			case 4:
			break;

			case 5:
			//Exit the Program
				return(0);
			default:
			//The user entered an invalid option
			cout << "Invalid Option, Please make a Valid Selection" << endl;
			break;
		}
	}


	cout << selection;


	return 0;
}
