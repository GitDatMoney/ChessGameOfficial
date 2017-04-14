using namespace std;
#include <iostream>


int msleep(unsigned long milisec)
{
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec=milisec-(sec*1000);
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    while(nanosleep(&req,&req)==-1)
        continue;
    return 1;
}


void tutorials ()
{
  string initCol;
  string initRow;
  string finCol;
  string finRow;
  int x1,x2,y1,y2;
  int quickPlay;
  char x1C, x2C;
  string tempX1, tempX2;
  bool gettingMove = true;
  int col1 = (int)'D' - 64;
  int row1 = 6;
  int row2 = 5;
  int inputPawn[8][8] = {
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'p','p','p','p','p','p','p','p'},
                      {'*','*','*','*','*','*','*','*'}
                      };
  int inputPawnCap[8][8] = {
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','B','*','*','*'},
                      {'*','*','*','p','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'}
                      };
  int inputRook[8][8] = {
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','P','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','r','*','*'},
                      {'*','*','*','*','*','*','*','*'}
                      };
  int inputBishop[8][8] = {
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','b','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'K','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'},
                      {'*','*','*','*','*','*','*','*'}
                      };

  // ChessGUI tutGui;
  // chess* tutBoard = new chess();



  ChessGUI tutGui;
  chess* tutBoard = new chess();
  chess* intBoardPawn = new chess();
  chess* intBoardRook = new chess();
  chess* intBoardPawnCap = new chess();
  chess* intBoardBishop = new chess();



  // this clears the screen
  cout << string(50, '\n');
  cout << endl;
  cout << endl;

cout << "\t\t Welcome to the tutorials section!" << endl;
cout << endl;
cout << endl;

cout << "\t    ███     ███    █▄      ███      ▄██████▄     ▄████████  ▄█     ▄████████  ▄█          ▄████████ \n";
cout << "\t ████████▄ ███    ███ ▀█████████▄ ███    ███   ███    ███ ███    ███    ███ ███         ███    ███ \n";
cout << "\t  ▀███▀▀██ ███    ███    ▀███▀▀██ ███    ███   ███    ███ ███▌   ███    ███ ███         ███    █▀  \n";
cout << "\t   ███   ▀ ███    ███     ███   ▀ ███    ███  ▄███▄▄▄▄██▀ ███▌   ███    ███ ███         ███        \n";
cout << "\t   ███     ███    ███     ███     ███    ███ ▀▀███▀▀▀▀▀   ███▌ ▀███████████ ███       ▀███████████ \n";
cout << "\t   ███     ███    ███     ███     ███    ███ ▀███████████ ███    ███    ███ ███                ███ \n";
cout << "\t   ███     ███    ███     ███     ███    ███   ███    ███ ███    ███    ███ ███▌    ▄    ▄█    ███ \n";
cout << "\t  ▄████▀   ████████▀     ▄████▀    ▀██████▀    ███    ███ █▀     ███    █▀  █████▄▄██  ▄████████▀      \n";


    //tutSkillLvl holds which level tutorial the user wants
    int tutSkillLvl = -1;

    // next cout statements are a menu to ask the user what kind of tutorials they want
    cout << endl;
    cout << endl;

    while (tutSkillLvl != 4){

    cout << "\t\t\t\t\t Aye fam, what kinda skills you got?" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t 1: Beginner" << endl;
    cout << "\t\t\t\t\t\t 2: Intermediate" << endl;
    cout << "\t\t\t\t\t\t 3: Dank as fuck" << endl;
    cout << endl;
    cout << "\t\t\t\t\t\t 4: Exit tutorials" << endl;

    // take the kind of tutorials they want as input and then use it as a switch statement
    cin >> tutSkillLvl;
    switch(tutSkillLvl)
    {
    // they choose a beginner tutorial
    case 1:
        cout << string(50, '\n');
        cout << "\t\t\t\t\t\t Hi there!" << endl;
        msleep(3000);
        cout << "\t\t\t\t I know you're a beginner so lets take it slow" << endl;
        msleep(3000);
        cout << endl;
        cout << "\t\t First things first, let me teach you what this program is and how it works" << endl;
        msleep(2000);
        cout << "\t\t\t\t This is a text-based chess game." << endl;
        msleep(3000);
        cout << "\t\t When you first entered the program, you were greeted with a menu that looked like this: " << endl;
        cout << endl;

        msleep(3000);

        cout << "\t\t\t\t\tPlease Select A Menu Option: " << endl;
    		cout << "\t\t\t\t\t1) Quick Play\n\t\t\t\t\t2) Custom Match\n\t\t\t\t\t3) Tutorials\n\t\t\t\t\t4) Options\n\t\t\t\t\t5) Exit" << endl;

        msleep(3000);
        cout << endl;
        cout << endl;

        cout << "\t\t\t If you would have selected Quick Play, a chess match would have begun." << endl;
        msleep(2500);
        cout << "\t So, enter the number 1 to select quick play and let's teach you how to use the chess program" << endl;
        cin >> quickPlay;
        while(cin.fail() || quickPlay != 1)
        {
          cin.clear();
          cin.ignore(1000,'\n');
          cout << "Thats not how you select Quick Play, try again newbie" << endl;
          cin >> quickPlay;
        }
        msleep(1200);
        cout << "\t\t\t\t\t Great, let's get started!" << endl;
        msleep(3000);
        cout << " \t\tAfter selecting quick play, you will be greeted with a chess board that looks like this: " << endl;
        msleep(2600);

        // tutBoard->setupBoard();
        // tutGui.printChessGUI(tutBoard->getBoard());

        tutBoard->setupBoard();
        tutGui.printChessGUI(tutBoard->getBoard());

        msleep(3000);

        cout << "\tYou will start as the white player, indicated by the letter w before the letter that denotes the piece being used." << endl;
        msleep(2500);
        cout << "\t\t\t\t\tFor example: " << endl;
        msleep(1500);
        cout << "\t\t\t\t\twp = white pawn" << endl;
        msleep(1500);
        cout << "\t\t\t\t\twb = white bishop" << endl;
        msleep(1500);
        cout << "\t\tThe only tricky one is wo, which is the white king. We had to use wk to represent the white knight" << endl;
        msleep(5500);
        cout << endl;

        cout << "\tIn order to actually play, the program will ask you to first input the column on which the piece you want to move resides." << endl;
        msleep(5000);
        cout << endl;
        cout << "\t\t\tThis is an alphabetical letter between A and H inclusive." << endl;
        msleep(4000);
        cout << endl;
        cout << "\t\t it will then ask you to input the corresponding row, which is a number between 1 and 8 inclusive" << endl;
        msleep(5000);
        cout << endl;
        cout << "\tFinally, you will have to enter the destination of the piece you want to move, which will follow the same format." << endl;
        msleep(5000);
        cout << endl;
        cout << "\t\t\t  Lets try this now, by moving a pawn " << endl;
        msleep(3500);
        cout << endl;
        cout << "\tYou may not know how specific pieces move yet, but a pawn is able to move one unit forward, so long as it is not blocked by another piece." << endl;
        msleep(5500);
        cout << endl;
        cout << "\t\tWithout further ado, allow me to present the board once again, and you try moving the pawn at D7 to D6" << endl;
        msleep(5000);
        cout << endl;

        tutGui.printChessGUI(tutBoard->getBoard());

        msleep(1500);

      while (initCol != "D" || initRow != "7" || finCol != "D" || finRow != "6")
      {
        cout << "White's turn" << endl;
        msleep(1000);
        cout << "Inital Column: ";
        cin >> initCol;
        cout << "Inital Row: ";
        cin >> initRow;
        cout << "Ending Column: ";
        cin >> finCol;
        cout << "Ending Row: ";
        cin >> finRow;

         if(initCol != "D" || initRow != "7" || finCol != "D" || finRow != "6")
         {
           msleep(1500);
           cout << "Try again buddy, move the pawn from D7 to D6" << endl;
           msleep(1500);
         }

      }

      msleep(1500);
      cout << "Great job, you were successful! The board will refresh to reflect your changes!" << endl;
      msleep(2000);





    //  tutBoard->move(0,0,0,2,'w');

    // MUST FIRGURE OUT HOW TO JUST GET THAT PIECE TO MOVE
    //CALL JONAH
      tutBoard->move(row1,col1-1,row2,col1-1,'w');
      tutGui.printChessGUI(tutBoard->getBoard());

      cout << "You have completed the beginner level tutorial!" << endl;
      cout << "Move on to the intermediate level tutorial to learn how all the pieces move." << endl;
      msleep(5000);

        break;
    // they choose an intermediate tutorial
    case 2:
        // this clears the screen
        cout << string(50, '\n');
        cout << endl;
        cout << endl;
        msleep(1000);
        cout << "\tWelcome to the intermediate tutorials!" << endl;
        cout << endl;
        msleep(1500);
        cout << "\tHere you will learn about the basics of chess: " << endl;
        cout << endl;
        msleep(3000);
        cout << "\t\t\t1) Basic movement of each piece" << endl;
        msleep(1000);
        cout << "\t\t\t2) Putting a king in check or checkmate" << endl;
        cout << endl;
        msleep(1000);
        cout << "\tThe advanced tutorials will teach you game strategy and advanced piece moves not mentioned here." << endl;
        cout << endl;
        msleep(3500);
        cout << "So when you're ready, select Quick Play and let's get started. " << endl;
        cout << endl;
        cout << endl;
        msleep(1500);
        cout << "\t\t\t\t\tPlease Select A Menu Option: " << endl;
    		cout << "\t\t\t\t\t1) Quick Play\n\t\t\t\t\t2) Custom Match\n\t\t\t\t\t3) Tutorials\n\t\t\t\t\t4) Options\n\t\t\t\t\t5) Exit" << endl;

        msleep(3000);
        cout << endl;
        cout << endl;

        cin >> quickPlay;
        while(cin.fail() || quickPlay != 1)
        {
          cin.clear();
          cin.ignore(1000,'\n');
          cout << "Thats not how you select Quick Play, try again newbie" << endl;
          cin >> quickPlay;
        }
        msleep(1200);
        cout << "\t\t\t\t\tLet's go!" << endl;
        cout << endl;
        msleep(2500);
        cout << "\tFirst we will learn about the pawn." << endl;
        cout << endl;
        msleep(1000);
        cout << "\tThe pawn is denoted by a p, and can only move forward by one square" << endl;
        cout << endl;
        msleep(2500);
        cout << "\tThere is one exception - the pawn can move forward either one or two squares from its starting point" << endl;
        cout << endl;
        msleep(4500);
        cout << "\tAfter it has moved from its starting point, it can only move one square forward at a time" << endl;
        cout << endl;
        msleep(4000);
        cout << "\tSo go ahead, try to move any of these pawns legally. They are all on the starting line" << endl;
        cout << endl;
        msleep(3000);

        intBoardPawn->setupCustomBoard(inputPawn);
        tutGui.printChessGUI(intBoardPawn->getBoard());

        intBoardPawn->getAllMoves('w');

        cout << "White's turn" << endl;
        gettingMove = true;
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

          if(intBoardPawn->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='%')
          {
            if (intBoardPawn->move(y1-1,x1-1,y2-1,x2-1,'w'))
            {
              if(x2-1 == 6)
              {
                intBoardPawn->move(7,7,7,5,'w');
                tutGui.printChessGUI(intBoardPawn->getBoard());
                gettingMove = false;
              }
              else
              {
                intBoardPawn->move(7,0,7,2,'w');
                tutGui.printChessGUI(intBoardPawn->getBoard());
                gettingMove = false;
              }

            }
            else{
              cout << "Invalid move, try again: " << endl;
            }
          }
          else if (intBoardPawn->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='t')
          {
            if (intBoardPawn->move(y1-1,x1-1,y2-1,x2-1,'w'))
            {
              tutGui.printChessGUI(intBoardPawn->getBoard());
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

        msleep(1000);
        cout << "\tGreat job! Now you know how a pawn can move." << endl;
        cout << endl;
        msleep(5000);
        // this clears the screen
        cout << string(50, '\n');
        cout << endl;
        cout << endl;
        cout << "\tOne more thing about the pawn - it can capture an opposing piece if it is diagonally in front of it by one square" << endl;
        cout << endl;
        msleep(2000);
        cout << "\tTry that by capturing the black bishop with the white pawn" << endl;
        cout << endl;
        msleep(2000);

        intBoardPawnCap->setupCustomBoard(inputPawnCap);
        tutGui.printChessGUI(intBoardPawnCap->getBoard());

        intBoardPawnCap->getAllMoves('w');

        cout << "White's turn" << endl;
        gettingMove = true;
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

          while(x2 != 5 || y2 != 5){
            if(intBoardPawnCap->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='t')
            {
                cout << "That move does not capture the bishop, try again by moving the pawn to the space where the bishop is." << endl;
            }
            else{
                cout << "That's not a legal move. The pawn can move forward by one square or capture diagonally forward by one square. Try again." << endl;
            }
            cout << "Ending Column: ";
            cin >> tempX2;
            checkCols(tempX2);
            x2C = tempX2[0];

            x2 = (int)x2C - 64;

            cout << "Ending Row: ";
            cin >> y2;
          }

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

          if(intBoardPawnCap->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='%')
          {
            if (intBoardPawnCap->move(y1-1,x1-1,y2-1,x2-1,'w'))
            {
              if(x2-1 == 6)
              {
                intBoardPawnCap->move(7,7,7,5,'w');
                tutGui.printChessGUI(intBoardPawnCap->getBoard());
                gettingMove = false;
              }
              else
              {
                intBoardPawnCap->move(7,0,7,2,'w');
                tutGui.printChessGUI(intBoardPawnCap->getBoard());
                gettingMove = false;
              }

            }
            else{
              cout << "Invalid move, try again: " << endl;
            }
          }
          else if (intBoardPawnCap->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='t')
          {
            if (intBoardPawnCap->move(y1-1,x1-1,y2-1,x2-1,'w'))
            {
              tutGui.printChessGUI(intBoardPawnCap->getBoard());
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
        msleep(1000);
        cout << "\tVery nice! Let's see what else you can do." << endl;
        cout << endl;
        msleep(2000);
        // this clears the screen
        cout << string(50, '\n');
        cout << endl;
        cout << endl;
        cout << "\tLet's move on to the rook, denoted by a r." << endl;
        cout << endl;
        msleep(2000);
        cout << "\tThe rook can move forward, backward, left or right to any space in a straight line from its starting point" << endl;
        cout << endl;
        msleep(4000);
        cout << "\tHowever, it cannot move past a piece that blocks movement past it" << endl;
        cout << endl;
        msleep(3000);
        cout << "\tTwo pieces also cannot occupy the same spot on a chess board" << endl;
        cout << endl;
        msleep(2000);
        cout << "\tA piece can capture an opposing player's piece if it moves onto the square that the opposing player's piece was at" << endl;
        cout << endl;
        msleep(2750);
        cout << "\tSo let's test what you've just learned. Capture the black pawn with the white rook" << endl;
        cout << endl;
        msleep(3000);

        intBoardRook->setupCustomBoard(inputRook);
        tutGui.printChessGUI(intBoardRook->getBoard());

        intBoardRook->getAllMoves('w');

        cout << "White's turn" << endl;
        gettingMove = true;
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

          while(x2 != 6 || y2 != 2){
            if(intBoardRook->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='t')
            {
                cout << "That move does not capture the pawn, try again by moving the rook to the space where the pawn is." << endl;
            }
            else{
                cout << "That's not a legal move. The rook can move forwards, backwards, up and down in a straight line but not through any pieces blocking it. Try again." << endl;
            }
            cout << "Ending Column: ";
            cin >> tempX2;
            checkCols(tempX2);
            x2C = tempX2[0];

            x2 = (int)x2C - 64;

            cout << "Ending Row: ";
            cin >> y2;
          }

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

          if(intBoardRook->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='%')
          {
            if (intBoardRook->move(y1-1,x1-1,y2-1,x2-1,'w'))
            {
              if(x2-1 == 6)
              {
                intBoardRook->move(7,7,7,5,'w');
                tutGui.printChessGUI(intBoardRook->getBoard());
                gettingMove = false;
              }
              else
              {
                intBoardRook->move(7,0,7,2,'w');
                tutGui.printChessGUI(intBoardRook->getBoard());
                gettingMove = false;
              }

            }
            else{
              cout << "Invalid move, try again: " << endl;
            }
          }
          else if (intBoardRook->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='t')
          {
            if (intBoardRook->move(y1-1,x1-1,y2-1,x2-1,'w'))
            {
              tutGui.printChessGUI(intBoardRook->getBoard());
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

        msleep(1000);
        cout << "\tExcellent work! You're getting the hang of this!" << endl;
        cout << endl;
        msleep(3500);
        // this clears the screen
        cout << string(50, '\n');
        cout << endl;
        cout << endl;
        cout << "\tMoving on to the bishop, denoted by a b. You captured one with your pawn earlier." << endl;
        cout << endl;
        msleep(2500);
        cout << "\tThe bishop moves similarly to the rook, but diagonally instead of straight." << endl;
        cout << endl;
        msleep(3000);
        cout << "\tAgain, it cannot move past pieces, and captures pieces that are on that diagonal line of movement." << endl;
        cout << endl;
        msleep(2500);
        cout << "\tSo let's see if you can do this one. Capture the black knight with the white bishop" << endl;
        cout << endl;
        msleep(3000);
        cout << endl;

        intBoardBishop->setupCustomBoard(inputBishop);
        tutGui.printChessGUI(intBoardBishop->getBoard());

        intBoardBishop->getAllMoves('w');

        cout << "White's turn" << endl;
        gettingMove = true;
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

          while(x2 != 1 || y2 != 6){
            if(intBoardBishop->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='t')
            {
                cout << "That move does not capture the knight, try again by moving the bishop to the space where the knight is." << endl;
            }
            else{
                cout << "That's not a legal move. The bishop can move forwards or backwards in a diagonal line but not through any pieces blocking it. Try again." << endl;
            }
            cout << "Ending Column: ";
            cin >> tempX2;
            checkCols(tempX2);
            x2C = tempX2[0];

            x2 = (int)x2C - 64;

            cout << "Ending Row: ";
            cin >> y2;
          }

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

          if(intBoardBishop->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='%')
          {
            if (intBoardBishop->move(y1-1,x1-1,y2-1,x2-1,'w'))
            {
              if(x2-1 == 6)
              {
                intBoardBishop->move(7,7,7,5,'w');
                tutGui.printChessGUI(intBoardBishop->getBoard());
                gettingMove = false;
              }
              else
              {
                intBoardBishop->move(7,0,7,2,'w');
                tutGui.printChessGUI(intBoardBishop->getBoard());
                gettingMove = false;
              }

            }
            else{
              cout << "Invalid move, try again: " << endl;
            }
          }
          else if (intBoardBishop->searchForMove(y1-1,x1-1,y2-1,x2-1,'w')=='t')
          {
            if (intBoardBishop->move(y1-1,x1-1,y2-1,x2-1,'w'))
            {
              tutGui.printChessGUI(intBoardBishop->getBoard());
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

        msleep(2000);
        cout << "\tSweet! Only a few more pieces to go." << endl;
        cout << endl;






        break;
    // they choose a Dank as fuck level tutorial
    case 3:
        cout << "AYEE DAT BOY DANK AS FUCK" << endl;
        cout << "Lemme teach you some dank as fuck things" << endl;
        cout << endl;
        cout << "Here goes some dank as fuck tutorial info stuff yo..." << endl;
        break;
    case 4:
        break;
    // they decide to fuck with the system
    default:
        cout << "stahp messing with the system yo." << endl;
        break;

    }
  }


}
