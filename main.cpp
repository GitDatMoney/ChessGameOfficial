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
	chess* theBoard = new chess();

	while(true) {
		cout << "Please Select A Menu Option: " << endl;
		cout << "1) Quick Play\n2) Custom Match\n3) Tutorials\n4) Options\n5) Exit" << endl;
		cin >> selection;
		int x1,x2,y1,y2;

		switch(selection) {
			case 1:
				cout << "Beginning Game: \n\n" << endl;
				theBoard->setupBoard();
				cout << "Inital Row: ";
				cin >> y1;
				cout << "Inital Column: ";
				cin >> x1;
				cout << "Ending Row: ";
				cin >> y2;
				cout << "Ending Column: ";
				cin >> x2;

				theBoard->move(x1,y1,x2,y2);
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
