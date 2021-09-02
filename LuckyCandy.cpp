#include <iostream>
#include <ctime>
#include <limits>
using namespace std;

void playerinfo(string[]); // array by default is passed by reference
void whotakescandy(bool, string[]);
void congrats(bool, string[]);


int main()
{
    int totalcandy = 0, candytaken = 0, Maxcandy = 0;
    string playernames[2];
    string continuegame;

    const float perturn = 0.5;
    const int MaxCandy = 100;
    int candyperturn = 0; 
    
    //Enter Players' info ------------------------------------
    
    playerinfo(playernames);

    //Game starts here --------------------------------------

    do {
        bool player1turn = true; // default player 1 goes first
        bool Endofgame = false;

        srand(time(nullptr));

        totalcandy = (rand() % MaxCandy) + 2;
        cout << "\nWe have " << totalcandy << " candy in total!\n";

        while (Endofgame == false)
        {
            whotakescandy(player1turn, playernames);

            candyperturn = perturn * totalcandy;
            cout << "The maximum number of candy you can take is ";

            if (candyperturn == 0) 
                cout << "1\n";
            else 
                cout << candyperturn << endl;

            cin >> candytaken;

            while (!cin) {
                cout << "\nInvalid input, please enter an integer that doesn't exceed the maximum candy allowed";
                cout << "\nHow many candy would you like to take?\n ";
                cin.clear();
                cin.ignore(numeric_limits <streamsize>::max(),'\n');
                cin >> candytaken;
            }

            while ((candytaken > candyperturn) && (totalcandy != 1)) {

                cout << "\nInvalid. You cannot take candy more than allowed - please enter number of candy you would like to take again: \n";
                cin.clear(); // discard previous input
                cin.ignore();
                cin >> candytaken;
            }

            while (candytaken == 0) {

                cout << "\nInvalid. You have to take at least 1 candy - please enter number of candy you would like to take again: \n";
                cin.clear();
                cin.ignore();
                cin >> candytaken;
            }

            totalcandy = totalcandy - candytaken;
            cout << "There are " << totalcandy << " candy left. \n";

            if (totalcandy == 0) {

                Endofgame = true;
                congrats(player1turn, playernames);
                              
            }
            else 
                player1turn = !player1turn;
        }

        cout << "\nThank you for playing! Would you like another round of the game?";
        cout << "\nEnter 'Y' for yes, any other keyboard for no.";
        cin >> continuegame;

    } while (continuegame == "Y" || continuegame == "y");

    return 0;

    
}


void playerinfo(string playerinfo[]) {

    cout << "\nWelcome to LuckyCandy Game~\nThe player who takes the last candy will lose!" << endl;

    cout << "\nPlease enter the first player's name: ";
    cin >> playerinfo[0];

    cout << "\nPlease enter the second player's name: ";
    cin >> playerinfo[1];

    cout << "\nYou are all set, good luck " << playerinfo[0] << " and " << playerinfo[1] << " !\n" << endl;
}

void whotakescandy(bool player1, string name[]) {

    if (player1)
        cout << "\n" << name[0] << ", how many candy would you like to take?\n";
    else
        cout << "\n" << name[1] << ", how many candy would you like to take?\n";

}

void congrats(bool player1, string name[]) {

    if (player1)
        cout << "\nCongrats " << name[1] << ", you win!! :)" << endl;
    else
        cout << "\nCongrats " << name[0] << ", you win!! :)" << endl;
}