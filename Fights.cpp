#include "Fights.h"
#include "Stats.h"
#include "Fighters.h"
#include <iostream>
#include <vector>
#include<string>
#include<stdlib.h>
#include<conio.h>
using namespace std;
void Fights::ovof(Stats user, Stats opp)
{
	double u, o, hitmiss, acc, acc1, cont;
	while (true) {
		cout << "\n=============== HP ===============\n\n"<<user.name<<"'s HP : " << user.hp << "/100\t"<<opp.name<<"'s HP : " << opp.hp << " / 100\n" << user.name << "'s Ki: " << user.energy << "/100\t" << opp.name << "'s Ki : " << opp.energy << " / 100\n\n";
		if (user.hp == 0 || opp.hp == 0)
			break;
		cout << "===== CHOOSE YOUR MOVE ===== \n\nEnter the number next to the move to make your choice\n\n";
		for (int i = 0; i < 4; i++) 
			cout << i + 1 << ". " << user.moves[i]<<" - "<<user.movedesc[i]<<"\n";
		cout << "\n";
		cin >> u;
		if (u > 4 || u < 1) {
			cout << "\nPlease enter the numbers next to the moves only\n\n";
			continue;
		}
		u--;
		srand(time(NULL));
		hitmiss = 1 + (rand() % 100);
		acc = user.accuracy[u];
		acc -= opp.speed;
		if (user.energy < user.energycost[u]) {
			cout << user.name << " doesn't have enough ki to use " << user.moves[u]<<"!\n\n";
		}
		else if (hitmiss > acc) {
			cout << user.name << "'s attack missed!\n\n";
			user.energy -= user.energycost[u];
		}
		else {
			cout << "\n\n" << user.name << " used " << user.moves[u] << "!\n\n";
			opp.hp = opp.hp - ((user.moved[u] + (user.moved[u] * (user.attack / 100.0))) - (user.moved[u] * (opp.defense / 100.0)));
			user.energy -= user.energycost[u];
			if (user.hp <= 0 || opp.hp <= 0) {
				if (user.hp <= 0)
					user.hp = 0;
				else
					opp.hp = 0;
			}
		}
		cout << "=============== HP ===============\n\n" << user.name << "'s HP : " << user.hp << "/100\t" << opp.name << "'s HP : " << opp.hp << " / 100\n";
		cout<< user.name << "'s Ki: " << user.energy << "/100\t" << opp.name << "'s Ki : " << opp.energy << " / 100\n\n"<<"===================================\n\n";
		if (user.hp == 0 || opp.hp == 0)
			break;
		srand(time(NULL));
		o = (rand() % 3);
		hitmiss = 1 + (rand() % 100);
		acc1 = opp.accuracy[o];
		acc1 -= user.speed;
		if (opp.energy < opp.energycost[o]) {
			cout << opp.name << " tried to use " << opp.moves[o] << ", but doesn't have enough ki to use it!\n\n";
		}
		else if (hitmiss > acc1) {
			cout << opp.name << "'s attack missed!\n\n";
			opp.energy -= opp.energycost[o];
		}
		else {
			cout << "\n" << opp.name << " used " << opp.moves[o] << "!\n\n";
			user.hp = user.hp - ((opp.moved[o] + (opp.moved[o] * (opp.attack / 100.0))) - (opp.moved[o] * (user.defense / 100.0)));
			opp.energy -= opp.energycost[o];
			if (user.hp <= 0 || opp.hp <= 0) {
				if (user.hp <= 0)
					user.hp = 0;
				else
					opp.hp = 0;
			}
		}
		user.energy += 10;
		opp.energy += 10;
	}
	if (user.hp == 0 && opp.hp != 0)
		cout << user.name << "'s HP is depleted! " << opp.name << " wins!\n\n";
	else if (opp.hp == 0 && user.hp != 0)
		cout << opp.name << "'s HP is depleted! " << user.name << " wins!\n\n";
	else
		cout << "Both fighters' HP is depleted! It's user draw!\n\n";
}
