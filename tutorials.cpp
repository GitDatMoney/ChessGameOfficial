using namespace std;
#include <iostream>


void tutorials ()
{
    //tutSkillLvl holds which level tutorial the user wants
    int tutSkillLvl;

    // next cout statements are a menu to ask the user what kind of tutorials they want
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
