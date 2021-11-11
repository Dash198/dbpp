#include "Fighters.h"
#include "Stats.h"
#include <string>
#include <vector>
using namespace std;
vector<Stats> obv;

Fighters::Fighters()
{
	obv.resize(3);
}
void Fighters::initialize()
{
	obv[0].name = "Goku";
	obv[0].moves = { "Kamehameha","Kaioken Attack","Ki Blast","Spirit Bomb" };
	obv[0].moved = { 10,20,5,40 };

	obv[1].name = "Vegeta";
	obv[1].moves = { "Big Bang Attack","Final Flash","Galick Gun","Meteor Burst" };
	obv[1].moved = { 20,40,10,5 };

	obv[2].name = "Gohan";
	obv[2].moves = { "Gekiretsu Madan","Masenko","Kamehameha","Father-Son Kamehameha" };
	obv[2].moved = { 5,10,20,40 };
}
