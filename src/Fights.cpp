#include "Fights.h"
#include "Stats.h"
#include "Fighters.h"
#include <iostream>
#include <vector>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include"AbilitiesandMoves.h"
using namespace std;
AbilitiesandMoves am;
void Fights::ovof(Stats user, Stats opp)
{
	double u, o, hitmiss, acc, acc1, uendrain=0, oendrain=0;
	while (true) {
		cout << "\n=============== HP ===============\n\n"<<user.name<<"'s HP : " << user.hp << " / "<<user.thp<<"\t"<<opp.name<<"'s HP : " << opp.hp << " / "<<opp.thp<<"\n" << user.name << "'s Ki : " << user.energy << " / 100\t" << opp.name << "'s Ki : " << opp.energy << " / 100\n\n";
		if (user.hp == 0 || opp.hp == 0)
			break;
		cout << "===== CHOOSE YOUR MOVE ===== \n\nEnter the number next to the move to make your choice\n\n";
		for (int i = 0; i < 4; i++) 
			cout << i + 1 << ". " << user.moves[i]<<" - "<<user.movedesc[i]<<"\n\n";
		cout << "\n\nAbilities:\n\n";
		for (int i = 4; i < 6; i++)
			cout << i + 1 << ". " << user.abilities[i-4] << " - " << user.abdesc[i-4] << "\n\n";
		cout << "\n";
		cin >> u;
		if (u > 6 || u < 1) {
			cout << "\nPlease enter the numbers next to the moves only\n\n";
			continue;
		}
		u--;
		if (u < 4) {
			srand(time(NULL));
			hitmiss = 1 + (rand() % 100);
			acc = user.accuracy[u];
			acc -= opp.speed;
			if (user.energy < user.energycost[u]) {
				cout << user.name << " doesn't have enough ki to use " << user.moves[u] << "!\n\n";
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
		}
		else {
			u -= 4;
			cout << "\n\n" << user.name << " used " << user.abilities[u] << "!\n\n";
			user.effects = am.Effects(user.abilities[u]);
			if (user.abilities[u] == "Zenkai")
				user.hp -= (user.hp * user.effects[0]);
			else
				user.hp -= user.effects[0];
			if (user.abilities[u] == "Ki Charge" && user.energy <= 80)
				user.energy += 20;
			else if (user.abilities[u] == "Ki Charge" && user.energy > 80)
				user.energy += (100 - user.energy);
			else
				uendrain += user.effects[1];
			user.attack += user.effects[2];
			user.defense += user.effects[3];
			user.speed += user.effects[4];
			for (int z = 0; z < 4; z++)
				user.accuracy[z] += user.effects[5];
			opp.attack -= user.effects[6];
			opp.defense -= user.effects[7];
			opp.speed -= user.effects[8];
			for (int z = 0; z < 4; z++)
				opp.accuracy[z] -= user.effects[9];
		}
		if (user.energy <= 0&&uendrain!=0) {
			if (user.name == "Goku") {
				user.attack = 4;
				user.defense = 3;
				user.speed = 5;
				user.accuracy = { 90,80,100,75 };
			}
			else if (user.name == "Piccolo") {
				user.attack = 5;
				user.defense = 4;
				user.speed = 4;
				user.accuracy = { 75,80,100,90 };
			}
			uendrain = 0;
			user.energy = 0;
		}
		user.energy -= uendrain;
		cout << "=============== HP ===============\n\n" << user.name << "'s HP : " << user.hp << " / "<<user.thp<<"\t" << opp.name << "'s HP : " << opp.hp << " / "<<opp.thp<<"\n";
		cout<< user.name << "'s Ki: " << user.energy << "/100\t" << opp.name << "'s Ki : " << opp.energy << " / 100\n\n"<<"===================================\n\n";
		if (user.hp == 0 || opp.hp == 0)
			break;
		srand(time(NULL));
		o = (rand() % 6);
		
		if (o < 4) {
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
		}
		else {
			o -= 4;
			cout << "\n\n" << opp.name << " used " << opp.abilities[o] << "!\n\n";
			opp.effects = am.Effects(opp.abilities[o]);
			if (opp.abilities[o] == "Zenkai")
				opp.hp -= (opp.hp * opp.effects[0]);
			else
				opp.hp -= opp.effects[0];
			if (opp.abilities[o] == "Ki Charge" && opp.energy <= 80)
				opp.energy += 20;
			else if (opp.abilities[o] == "Ki Charge" && opp.energy > 80)
				opp.energy += (100 - opp.energy);
			else
				oendrain += opp.effects[1];
			opp.attack += opp.effects[2];
			opp.defense += opp.effects[3];
			opp.speed += opp.effects[4];
			for (int z = 0; z < 4; z++)
				opp.accuracy[z] += opp.effects[5];
			user.attack -= opp.effects[6];
			user.defense -= opp.effects[7];
			user.speed -= opp.effects[8];
			for (int z = 0; z < 4; z++)
				user.accuracy[z] -= opp.effects[9];
		}
		if (opp.energy <= 0 && oendrain != 0) {
			if (opp.name == "Goku") {
				opp.attack = 4;
				opp.defense = 3;
				opp.speed = 5;
				opp.accuracy = { 90,80,100,75 };
			}
			else if (opp.name == "Piccolo") {
				opp.attack = 5;
				opp.defense = 4;
				opp.speed = 4;
				opp.accuracy = { 75,80,100,90 };
			}
			oendrain = 0;
			opp.energy = 0;
		}
		opp.energy -= oendrain;
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
