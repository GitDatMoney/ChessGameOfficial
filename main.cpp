
//main.cpp
//Chess Initial Files
#include "main.h"
using namespace std;
// #include <iostream>
#include <string>

// this is called when the user selects option 3 (tutorials) in the main menu

int main() {
	ChessGUI theGui;
	theGui.welcomeToChess();
	int selection = 0;
	cout << "Welcome To Chess" << endl;
	chess* theBoard = new chess();


	while(true) {
		cout << "Please Select A Menu Option: " << endl;
		cout << "1) Quick Play\n2) Custom Match\n3) Tutorials\n4) Exit" << endl;
		cin >> selection;
		int x1,x2,y1,y2;
		char x1C, x2C;
		CustomMatch customMatch;
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
					if (theBoard->checkForCheckmate('w'))
					{
						cout << "White is in checkmate, black wins!" << endl;
						return 0;
					}
					while(gettingMove)
					{
						cout << "Inital Column: ";
            cin >> tempX1;

            checkCols(tempX1);

            x1C = tempX1[0];

						x1 = (int)x1C - 64;  //Converts character to int, need to add bound checking mechanism and make it case insensitive

						cout << "Inital Row: ";
						cin >> y1;

            while(cin.fail() || y1 < 1 || y1 > 8)
            {
              if(cin.fail())
              {
                cout << "Please enter a valid row number: ";
              }
              else {
                cout <<"Please enter a valid row number: ";
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
                cout << "Please enter a valid row number: ";
              }
              else {
                cout <<"Please enter a valid row number: ";
              }
              cin.clear();
              cin.ignore(1000,'\n');

              cin >> y2;
            }

						if(theBoard->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='%')
						{
							if (theBoard->move(y1-1,x1-1,y2-1,x2-1,'w'))
							{
								if(x2-1 == 6)
								{
									theBoard->move(7,7,7,5,'w');
									theGui.printChessGUI(theBoard->getBoard());
									gettingMove = false;
								}
								else
								{
									theBoard->move(7,0,7,3,'w');
									theGui.printChessGUI(theBoard->getBoard());
									gettingMove = false;
								}

							}
							else{
								cout << "Invalid move, try again: " << endl;
							}
						}
						else if (theBoard->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='t')
						{
							if (theBoard->move(y1-1,x1-1,y2-1,x2-1,'w'))
							{
								theGui.printChessGUI(theBoard->getBoard());
								gettingMove = false;
							}
							else
							{
								cout << "Invalid move, try again: " << endl;
							}
						}
						else{
							cout << "Invalid move, try again: " << endl;
						}
					}
					gettingMove = true;
					cout << "Black's turn" << endl;
					if (theBoard->checkForCheckmate('b'))
					{
						cout << "Black is in checkmate, white wins!" << endl;
						return 0;
					}
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
                cout << "Please enter a valid row number: ";
              }
              else {
                cout <<"Please enter a valid row number: ";
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
                cout << "Please enter a valid row number: ";
              }
              else {
                cout <<"Please enter a valid row number: ";
              }
              cin.clear();
              cin.ignore(1000,'\n');

              cin >> y2;
            }

						if(theBoard->searchForMove(y1-1,x1-1,y2-1,x2-1,'b')=='%')
						{
							if (theBoard->move(y1-1,x1-1,y2-1,x2-1,'b'))
							{
								if(x2-1 == 6)
								{
									theBoard->move(0,7,0,5,'b');
									theGui.printChessGUI(theBoard->getBoard());
									gettingMove = false;
								}
								else
								{
									theBoard->move(0,0,0,3,'b');
									theGui.printChessGUI(theBoard->getBoard());
									gettingMove = false;
								}

							}
							else{
								cout << "Invalid move, try again: " << endl;
							}
						}
						else if (theBoard->searchForMove(y1-1,x1-1,y2-1,x2-1,'b')=='t')
						{
							if (theBoard->move(y1-1,x1-1,y2-1,x2-1,'b'))
							{
								theGui.printChessGUI(theBoard->getBoard());
								gettingMove = false;
							}
							else
							{
								cout << "Invalid move, try again: " << endl;
							}
						}
						else{
							cout << "Invalid move, try again: " << endl;
						}
					}
				}

				//x1, y1 are starting position:x2,y2 are ending position
			break;

			case 2:
					customMatch.beginTimedMatch();
			break;

			case 3:

			    tutorials();
			break;

			case 4: //Exits the program
				return(0);
			break;

			default:
			//The user entered an invalid option
			cout << "Invalid Option, Please make a Valid Selection" << endl;
			break;
		}
	}


	cout << selection;


	return 0;
}
void generateCustomMatch(int userInput) {

}

void clearCin() {
	cin.ignore(100000, '\n');
}

//Takes in user input inside of the function, attempts to convert the string into an int, and returns the int if successful. If the input
//was not of type int, an exception is thrown and caught in the method that called userInputInt()
int userInputInt() {
	string inputS;
	int inputI = 0;
	cin >> inputS;
	cout << endl;

	//Converts the character array into an int, throwing an exception if it wasn't able to
	try {
		inputI = stoi(inputS,nullptr,0);
	} catch(...) {
		return 0;
	}
	return inputI;
}
