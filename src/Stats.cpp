#include "Stats.h"
#include <string>
#include <vector>
using namespace std;

Stats::Stats()
{
	attack = 0;
	defense = 0;
	speed = 0;
	name = "";
	hp = 100;
	thp = hp;
	energy = 100;
	moves.resize(4);
	moved.resize(4);
	movedesc.resize(4);
	accuracy.resize(4);
	energycost.resize(4);
	moves = { "","","","" };
	abilities.resize(2);
	abdesc.resize(2);
	effects.resize(10);
	effects = {0,0,0,0,0,0,0,0,0,0};   //format: hp, energy drain, attack, defense, speed, accuracy, opp att, opp def, opp spe, opp acc
}
