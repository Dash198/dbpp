// DBPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Stats.h"
#include "Fighters.h"
#include "Fights.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    Fighters f;
    Fights fs;
    f.initialize();
    char y;
    int c, c1;
    cout << "=========== DRAGON BALL ++ ===========\n\nWelcome! Do you want to play? (y/n)\n";
    cin >> y;
    while (y == 'y') {
        cout << "\n\n====== CHOOSE YOUR FIGHTER ======\n\nEnter the corresponding number to make your choice\n";
        for (int i = 0; i < f.obv.size(); i++)
            cout << i + 1 << ". " << f.obv[i].name << "\n";
        cout << "\n";
        cin >> c;
        c--;
        cout << "\n\n====== CHOOSE YOUR OPPONENT ======\n\nEnter the corresponding number to make your choice\n";
        for (int i = 0; i < f.obv.size(); i++)
            cout << i + 1 << ". " << f.obv[i].name << "\n";
        cout << "\n";
        cin >> c1;
        c1--;
        fs.ovof(f.obv[c],f.obv[c1]);
        cout << "Do you want to play again? (y/n)\n\n";
        cin >> y;
    }
    cout << "\n\nGoodbye! Thanks for playing!\n\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
