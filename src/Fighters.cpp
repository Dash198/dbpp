#include "Fighters.h"
#include "Stats.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "SaveLoad.h"
using namespace std;
ifstream in("CharData.txt");
string s;
SaveLoad sl;
int fcount = 0;
Fighters::Fighters()
{
	fcount = sl.loadFighters() + 1;
	fighter.resize(fcount);
}
void Fighters::initialize()
{
	for (int i = 0; i < fighter.size(); i++) {
		getline(in, s);
		fighter[i].name = s;
		getline(in, s);
		fighter[i].hp = stod(s);
		fighter[i].thp = fighter[i].hp;
		for (int j = 0; j < 4; j++) {
			getline(in, s);
			fighter[i].moves[j] = s;
			getline(in, s);
			fighter[i].movedesc[j] = s;
			getline(in, s);
			fighter[i].moved[j] = stod(s);
			getline(in, s);
			fighter[i].energycost[j] = stoi(s);
			getline(in, s);
			fighter[i].accuracy[j] = stod(s);
		}
		getline(in, s);
		fighter[i].attack = stod(s);
		getline(in, s);
		fighter[i].defense = stod(s);
		getline(in, s);
		fighter[i].speed = stod(s);
		getline(in, s);
	}
	
}
