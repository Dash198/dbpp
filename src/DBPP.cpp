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
    Fighters ft;
    Fights fight;
    ft.initialize();
    char choice;
    int userchoice, oppchoice;
    cout << "=========== DRAGON BALL ++ ===========\n\nWelcome! Do you want to play? (y/n)\n";
    cin >> choice;
    while (choice == 'y') {
        cout << "\n\n====== CHOOSE YOUR FIGHTER ======\n\nEnter the corresponding number to make your choice\n\n";
        for (int i = 0; i < ft.fighter.size(); i += 3) {
            for (int j = i; j < i + 3; j++) {
                if (j >= ft.fighter.size())
                    break;
                cout << j + 1 << ". " << ft.fighter[j].name << "     ";
            }
            cout << "\n";
        }
        cout << "\n";
        cin >> userchoice;
        userchoice--;
        if (userchoice >= ft.fighter.size()) {
            cout << "Enter a valid number!";
            continue;
        }
        cout << "\n\n====== CHOOSE YOUR OPPONENT ======\n\nEnter the corresponding number to make your choice\n\n";
        for (int i = 0; i < ft.fighter.size(); i += 3) {
            for (int j = i; j < i + 3; j++) {
                if (j >= ft.fighter.size())
                    break;
                cout << j + 1 << ". " << ft.fighter[j].name << "     ";
            }
            cout << "\n";
        }
        cout << "\n";
        cin >> oppchoice;
        oppchoice--;
        fight.ovof(ft.fighter[userchoice],ft.fighter[oppchoice]);
        cout << "Do you want to play again? (y/n)\n\n";
        cin >> choice;
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
