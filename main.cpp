//main.cpp
//Chess Initial Files
#include "chess.h"
#include <iostream>

using namespace std;
#include <iostream>

using namespace std;

int main() {

	int selection = 0;
	cout << "Welcome To Chess" << endl;
	bool toBreak = false;
	//You don't need to use new unless you are making a pointer, which we don't need here
	chess theBoard = chess();
	//Just to test that the board initializes correctly
	theBoard.printBoard();

	while(true) {
		cout << "Please Select A Menu Option: " << endl;
		cout << "1) Quick Play\n2) Custom Match\n3) Tutorials\n4) Options\n5) Exit" << endl;
		cin >> selection;
		int x1,x2,y1,y2;

		switch(selection) {
			case 1:
				cout << "Beginning Game: \n\n" << endl;
				// theBoard->setupBoard();
				cout << "Inital Row: ";
				cin >> y1;
				cout << "Inital Column: ";
				cin >> x1;
				cout << "Ending Row: ";
				cin >> y2;
				cout << "Ending Column: ";
				cin >> x2;
					//x1,y1 are the position the user wants to move a piece from,
					//X2,y2 are the position the user wants to move a piece to,

				//I need you to find a way to make the following line of code work, change it what way you need
				// and leave LOTS of comments on what you did.
				
				//theBoard->chessPieceArray[x1][y1]->pieceMove(x2,y2, theBoard->chessPieceArray);
				//Sam: We're trying to access the array, however the array is a private data member inside of the chess object
				//so we have to write an intermediary function to pass the values through
				//Check chess::move();
				theBoard.move(x1,y1,x2,y2);

			break;

			case 2:
			break;

			case 3:
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
