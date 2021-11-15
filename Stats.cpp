#include "Stats.h"
#include <string>
#include <vector>
using namespace std;
string name;
double hp;
vector<string> moves;
vector<double> moved;

Stats::Stats()
{
	attack = 0;
	defense = 0;
	name = "";
	hp = 100;
	energy = 100;
	moves.resize(4);
	moved.resize(4);
}
