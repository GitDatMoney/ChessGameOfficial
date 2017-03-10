//main.cpp
//Chess Initial Files
#include "chess.h"
#include <iostream>

using namespace std;
#include <iostream>

using namespace std;

// this is called when the user selects option 3 (tutorials) in the main menu
void tutorials ()
{
    //tutSkillLvl holds which level tutorial the user wants
    int tutSkillLvl;

    // next cout statements are a menue to ask the user what kind of tutorials they want
    cout << "Aye fam, what kinda skills you got?" << endl;
    cout << endl;
    cout << "1: Beginner" << endl;
    cout << "2: Intermediate" << endl;
    cout << "3: Dank as fuck" << endl;
    cout << "4: Gary Kasparov" << endl;
    cout << "5: Deep Blue" << endl;

    // take the kind of tutorials they want as input and then use it as a switch statement
    cin >> tutSkillLvl;

    switch(tutSkillLvl)
    {
    // they choose a beginner tutorial
    case 1:
        cout << "Aye fam you a beginner" << endl;
        cout << "Lemme teach you some beginner things" << endl;
        cout << endl;
        cout << "Here goes some beginner tutorial info stuff yo..." << endl;
        cout << "Knock yourself out" << endl;
        break;
    // they choose an intermediate tutorial
    case 2:
        cout << "Aye fam you an intermediate" << endl;
        cout << "Lemme teach you some intermediate things" << endl;
        cout << endl;
        cout << "Here goes some intermediate tutorial info stuff yo..." << endl;
        break;
    // they choose a Dank as fuck level tutorial
    case 3:
        cout << "AYEE DAT BOY DANK AS FUCK" << endl;
        cout << "Lemme teach you some dank as fuck things" << endl;
        cout << endl;
        cout << "Here goes some dank as fuck tutorial info stuff yo..." << endl;
        break;
    // they choose a Kasparov level tutorial
    case 4:
        cout << "why are you checking tutorials" << endl;
        break;
    // they decide they are Deep Mind
    case 5:
        cout << "There is supposed to be some funny ascii text but it doesnt work" << endl;
        //cout << "╭∩╮(ô¿ô)╭∩╮" << endl;
        break;
    // they decide to fuck with the system
    default:
        cout << "stahp messing with the system yo." << endl;
        break;

    }


}

int main() {

	int selection = 0;
	cout << "Welcome To Chess" << endl;
	bool toBreak = false;
	chess* theBoard = new chess();
	chessPiece** myBoard = theBoard->getBoard();
	
	while(true) {
		cout << "Please Select A Menu Option: " << endl;
		cout << "1) Quick Play\n2) Custom Match\n3) Tutorials\n4) Options\n5) Exit" << endl;
		cin >> selection;
		int x1,x2,y1,y2;
		switch(selection) {
			case 1:
				cout << "Beginning Game: \n\n" << endl;
				theBoard->setupBoard();
			//	cout << myBoard[3][1].get_pieceType() << endl;
			//	cout << myBoard[7][2].getMoves(7,2,myBoard) << endl;
				while(true)
				{
					theBoard->getAllMoves('w');
					cout << "Inital Row: ";
					cin >> y1;
					cout << "Inital Column: ";
					cin >> x1;
					cout << "Ending Row: ";
					cin >> y2;
					cout << "Ending Column: ";
					cin >> x2;
					if(theBoard->searchForMove(y1-1,x1-1,y2-1,x2-1,'w'))
					{
						if (theBoard->move(y1-1,x1-1,y2-1,x2-1,'w'))
						{
							theBoard->printBoard();
						}
					}
					cout << "Black's turn" << endl;
					theBoard->getAllMoves('b');
					cout << "Inital Row: ";
					cin >> y1;
					cout << "Inital Column: ";
					cin >> x1;
					cout << "Ending Row: ";
					cin >> y2;
					cout << "Ending Column: ";
					cin >> x2;
					if(theBoard->searchForMove(y1-1,x1-1,y2-1,x2-1,'b'))
					{
						if (theBoard->move(y1-1,x1-1,y2-1,x2-1,'b'))
						{
							theBoard->printBoard();
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
