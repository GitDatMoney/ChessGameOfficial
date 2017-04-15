/*
  This class defines and implements the conditions for a Custom Match
*/
#include "CustomMatch.h"
using namespace std;

CustomMatch::CustomMatch() {

}
void CustomMatch::printCustomMatchMenu() {
  cout << "\nPlease Select a Menu Option \n" << endl;
  cout << "1) Timed Match" << endl;
  cout << "2) Load Saved Game" << endl;
  cout << "3) Start From a Random Setup" << endl;
}
void CustomMatch::generateCustomMatch(int userInput) {
  switch (userInput){
    case 1:
          this->beginTimedMatch();
      break;
    case 2:
      break;
    default:
      break;
  }
}



string CustomMatch::secondsToTime(int seconds)
{
	stringstream ss;
	if (seconds > 60)
	{
		ss << seconds/60;
		
		ss << ":";
		if (seconds%60 < 10)
		{
			ss << "0";
		}
		ss <<seconds%60;
	}
	else{
		ss << seconds << " seconds";
	}
	return ss.str();
}

void CustomMatch::beginTimedMatch() {

    int mode;
    double wTime;
    double bTime;
    double totalTime;
    string tempX1, tempX2;
    int x1,x2,y1,y2;
    int userInput = 0;
    int numCustomMatchLoops = 0;
    char x1C, x2C;
    ChessGUI theGui;
    int timeMode;
    cout << "Select a timed mode: " << endl;
    cout<< "1) Sudden Death" << endl;
    cout << "Each player has a set amount of time, whoever's timer runs out first loses." << endl;
    cout <<"2) Overtime" << endl;
    cout << "Time will increase after a certain number of moves" << endl;
    cout << "3) Hourglass" << endl;
    cout << "As one player's timer decreases, the other player's timer increases." << endl;
	cout << "4) Exit to menu" << endl;
	cin >> mode;
	while(cin.fail() || mode < 1 || mode > 4)
	{
	  cout << "Enter a valid option: " << endl;
	  cin.clear();
	  cin.ignore(1000,'\n');

	  cin >> mode;
	}
	if (mode == 4)
	{
		return;
	}
    cout << "Select a game pace" << endl;
    cout<< "1) Long" << endl;
    cout<< "2) Rapid" << endl;
    cout<< "3) Blitz" << endl;
	cin >> timeMode;
	while(cin.fail() || timeMode < 1 || timeMode > 3)
	{
	  cout << "Enter a valid option: " << endl;
	  cin.clear();
	  cin.ignore(1000,'\n');

	  cin >> timeMode;
	}
    switch(timeMode)
    {
      case(1):
        totalTime=10800;
        break;
      case(2):
        totalTime=1800;
        break;
      case(3):
        totalTime=900;
        break;
    }
    wTime = totalTime;
    bTime = totalTime;
    double seconds_since_start;
    switch(mode)
    {
      case 1:
	  {

        chess* theBoard = new chess();
        theBoard->setupBoard();
        time_t start = time(0);
        cout << "White remaining time: " << wTime << endl;
        while(true)
        {
          theGui.printChessGUI(theBoard->getBoard());
          cout << "Black remaining time: " << bTime << endl;

        chess* theBoard = new chess();
        theBoard->setupBoard();
        time_t start = time(0);
        while(true)
        {

          theGui.printChessGUI(theBoard->getBoard());
		cout << "White remaining time: " << this->secondsToTime(wTime) << endl;
		
        if(bTime >0)
		{
	      cout << "Black remaining time: " << this->secondsToTime(bTime) << endl;
		}
		else{
			cout << "Black is out of time, White wins!" << endl;
			return;
		}
          start = time(0);
          theBoard->getAllMoves('w');
          bool gettingMove = true;
          cout << "White's turn" << endl;
			if (theBoard->checkForCheckmate('w'))
			{
				cout << "White is in checkmate, Black wins!" << endl;
				return;
			}
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
                  theBoard->move(7,0,7,2,'w');
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
          seconds_since_start = difftime( time(0), start);
          wTime-=seconds_since_start;
          		if(wTime >0)
			{
			  cout << "White remaining time: " << this->secondsToTime(wTime) << endl;
			}
			else{
				cout << "White is out of time, Black wins!" << endl;
				return;
			}
			cout << "Black remaining time: " << this->secondsToTime(bTime) << endl;
          start = time(0);
          gettingMove = true;
          cout << "Black's turn" << endl;
			if (theBoard->checkForCheckmate('b'))
			{
				cout << "Black is in checkmate, White wins!" << endl;
				return;
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
                  theBoard->move(0,0,0,2,'b');
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
          seconds_since_start=difftime(time(0),start);
          bTime-=seconds_since_start;
        

		}
	}
			break;
	  }
	      case 2:
		  {
			chess* theBoard = new chess();
			theBoard->setupBoard();
			time_t start = time(0);
			int bMoves=0;
			int wMoves=0;
			int reqTurn;
			if(totalTime==10800)
			{
				reqTurn=60;
			}
			else if(totalTime==1800)
			{
				reqTurn=45;
			}
			else{
				reqTurn=30;
			}
			while(true)
			{
			  theGui.printChessGUI(theBoard->getBoard());

			cout << "White remaining time: " << this->secondsToTime(wTime) << endl;
			if(bTime >0)
			{
			  cout << "Black remaining time: " << this->secondsToTime(bTime) << endl;
			}
			else{
				cout << "Black is out of time, White wins!" << endl;
				return;
			}
			  start = time(0);
			  theBoard->getAllMoves('w');
			  bool gettingMove = true;
			  cout << "White's turn" << endl;
			if (theBoard->checkForCheckmate('w'))
			{
				cout << "White is in checkmate, Black wins!" << endl;
				return;
			}
			  if(wMoves==reqTurn)
			  {
				  wTime+=(totalTime/2);
			  }
			  else if (wMoves < reqTurn)
			  {
				  cout << "Turns until more time: " << reqTurn-wMoves << endl;
			  }
			  wMoves++;
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
					  theBoard->move(7,0,7,2,'w');
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
			  seconds_since_start = difftime( time(0), start);
			  wTime-=seconds_since_start;
					if(wTime >0)
				{
				  cout << "White remaining time: " << this->secondsToTime(wTime) << endl;
				}
				else{
					cout << "White is out of time, Black wins!" << endl;
					return;
				}
			  start = time(0);
			  gettingMove = true;
			  cout << "Black's turn" << endl;
			if (theBoard->checkForCheckmate('b'))
			{
				cout << "Black is in checkmate, White wins!" << endl;
				return;
			}
			  theBoard->getAllMoves('b');
			  if(bMoves==reqTurn)
			  {
				  bTime+=(totalTime/2);
			  }
			   else if (bMoves < reqTurn)
			  {
				  cout << "Turns until more time: " << reqTurn-bMoves << endl;
			  }
			  bMoves++;
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
					  theBoard->move(0,0,0,2,'b');
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
			  seconds_since_start=difftime(time(0),start);
			  bTime-=seconds_since_start;
			}
			break;
		}
		
		case 3:
	  {
		  if (totalTime==10800)
		  {
			  totalTime = 3600;
		  }
		  else if (totalTime==1800)
		  {
			  totalTime = 900;
		  }
		  else{
			  totalTime=500;
		  }
        chess* theBoard = new chess();
        theBoard->setupBoard();
        time_t start = time(0);
        while(true)
        {
          theGui.printChessGUI(theBoard->getBoard());
			cout << "White remaining time: " << this->secondsToTime(wTime) << endl;
        if(bTime >0)
		{
	      cout << "Black remaining time: " << this->secondsToTime(bTime) << endl;
		}
		else{
			cout << "Black is out of time, White wins!" << endl;
			return;
		}

          start = time(0);
          theBoard->getAllMoves('w');
          bool gettingMove = true;
          cout << "White's turn" << endl;
			if (theBoard->checkForCheckmate('w'))
			{
				cout << "White is in checkmate, Black wins!" << endl;
				return;
			}
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
                  theBoard->move(7,0,7,2,'w');
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
          seconds_since_start = difftime( time(0), start);
          wTime-=seconds_since_start;

          cout << "White remaining time: " << wTime << endl;

          		if(wTime >0)
			{
			  cout << "White remaining time: " << this->secondsToTime(wTime) << endl;
			}
			else{
				cout << "White is out of time, Black wins!" << endl;
				return;
			}

          start = time(0);
          gettingMove = true;
          cout << "Black's turn" << endl;
			if (theBoard->checkForCheckmate('b'))
			{
				cout << "Black is in checkmate, White wins!" << endl;
				return;
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
                  theBoard->move(0,0,0,2,'b');
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
          seconds_since_start=difftime(time(0),start);
          bTime-=seconds_since_start;

        }

		  wTime+=seconds_since_start;
        
		break;
		}
	case 4:
		return;

    }
  }
