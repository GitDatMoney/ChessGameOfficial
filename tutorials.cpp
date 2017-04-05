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

  // ChessGUI tutGui;
  // chess* tutBoard = new chess();







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
        cout << "\t\t\t\t I know you're a begginer so lets take it slow" << endl;
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
        cout << "\t So, enter the number 1 to select quick play and lets teach you how to use the chess program" << endl;
        int quickPlay;
        cin >> quickPlay;
        while(cin.fail() || quickPlay != 1)
        {
          cin.clear();
          cin.ignore(1000,'\n');
          cout << "Thats not how you select Quick Play, try again newbie" << endl;
          cin >> quickPlay;
        }
        msleep(1200);
        cout << "\t\t\t\t\t Great, lets get started!" << endl;
        msleep(3000);
        cout << " After selecting quick play, you will be greeted with a chess board that looks like this: " << endl;
        msleep(2600);

        // tutBoard->setupBoard();
        // tutGui.printChessGUI(tutBoard->getBoard());
        msleep(3000);










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


}
