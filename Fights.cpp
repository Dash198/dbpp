#include "Fights.h"
#include "Stats.h"
#include "Fighters.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;
void Fights::ovof(Stats user, Stats opp)
{
	int u, o;
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
		if (user.energy < user.energycost[u]) {
			cout << user.name << " doesn't have enough ki to use " << user.moves[u]<<"!\n\n";
		}
		else {
			cout << "\n\n" << user.name << " used " << user.moves[u] << "!\n\n";
			opp.hp -= user.moved[u];
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
		if (opp.energy < opp.energycost[o]) {
			cout << opp.name << " tried to use " << opp.moves[o] << ", but doesn't have enough ki to use it!\n\n";
		}
		else {
			cout << "\n" << opp.name << " used " << opp.moves[o] << "!\n\n";
			user.hp -= opp.moved[o];
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
