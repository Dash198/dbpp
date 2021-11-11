#include "Stats.h"
#include <string>
#include <vector>
using namespace std;
string name;
int hp;
vector<string> moves;
vector<int> moved;

Stats::Stats()
{
	name = "";
	hp = 100;
	moves.resize(4);
	moved.resize(4);
}
