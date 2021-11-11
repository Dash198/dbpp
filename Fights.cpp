#include "Fights.h"
#include "Stats.h"
#include "Fighters.h"
#include <iostream>
#include <vector>
#include<string>
using namespace std;
void Fights::ovof(Stats a, Stats b)
{
	int u, o;
	while (true) {
		cout << "\n=============== HP ===============\n\n"<<a.name<<"'s HP : " << a.hp << "/100\t"<<b.name<<"'s HP : " << b.hp << " / 100\n\n";
		if (a.hp == 0 || b.hp == 0)
			break;
		cout << "===== CHOOSE YOUR MOVE ===== \n\nEnter the number next to the move to make your choice\n\n";
		for (int i = 0; i < 4; i++) 
			cout << i + 1 << ". " << a.moves[i]<<"\n";
		cout << "\n";
		cin >> u;
		if (u > 4 || u < 1) {
			cout << "\nPlease enter the numbers next to the moves only\n\n";
			continue;
		}
		u--;
		cout << "\n\n" << a.name << " used " << a.moves[u] << "!\n\n";
		b.hp -= a.moved[u];
		if (a.hp <= 0 || b.hp <= 0) {
			if (a.hp <= 0)
				a.hp = 0;
			else
				b.hp = 0;
		}
		cout << "=============== HP ===============\n\n"<<a.name<<"'s HP : " << a.hp << "/100\t"<<b.name<<"'s HP : " << b.hp << " / 100\n\n============================================== = \n\n";
		if (a.hp == 0 || b.hp == 0)
			break;
		srand(time(NULL));
		o = (rand() % 3);
		cout << "\n" << b.name << " used " << b.moves[o] << "!\n\n";
		a.hp -= b.moved[o];
		if (a.hp <= 0 || b.hp <= 0) {
			if (a.hp <= 0)
				a.hp = 0;
			else
				b.hp = 0;
		}
	}
	if (a.hp == 0 && b.hp != 0)
		cout << a.name << "'s HP is depleted! " << b.name << " wins!\n\n";
	else if (b.hp == 0 && a.hp != 0)
		cout << b.name << "'s HP is depleted! " << a.name << " wins!\n\n";
	else
		cout << "Both fighters' HP us depleted! It's a draw!\n\n";
}
