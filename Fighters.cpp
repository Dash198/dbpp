#include "Fighters.h"
#include "Stats.h"
#include <string>
#include <vector>
using namespace std;
vector<Stats> fighter;

Fighters::Fighters()
{
	fighter.resize(3);
}
void Fighters::initialize()
{
	fighter[0].name = "Goku";
	fighter[0].moves = { "Kamehameha","Kaioken Attack","Ki Blast","Spirit Bomb" };
	fighter[0].moved = { 10,20,5,40 };
	fighter[0].energycost = { 20,25,15,50 };
	fighter[0].movedesc = { "A powerful ki blast fired with two hands after concentrating a large amount of ki.","A powerful series of meelee attacks powered up by the Kaioken technique","A simple energy blast","Goku's strongest move, an energy ball made up of the ki of all sources of life around him" };

	fighter[1].name = "Vegeta";
	fighter[1].moves = { "Big Bang Attack","Final Flash","Galick Gun","Energy Blast Volley" };
	fighter[1].moved = { 20,40,10,5 };
	fighter[1].energycost = { 25,50,20,15 };
	fighter[1].movedesc = { "A high-power energy ball, fired at great speed towards the opponent","Charge ki at both of your hands, combine them together to form a high-damage energy beam","An energy beam similar to the Kamehameha","Fire a barrage of ki blasts at the opponent" };

	fighter[2].name = "Gohan";
	fighter[2].moves = { "Gekiretsu Madan","Masenko","Kamehameha","Father-Son Kamehameha" };
	fighter[2].moved = { 5,10,20,40 };
	fighter[2].energycost = { 15,20,25,50 };
	fighter[2].movedesc = { "Charge ki at both hands, and combine them to fire a barrage of energy waves at the opponent","Fire a powerful beam of energy","A powerful ki blast fired with two hands after concentrating a large amount of ki.","A double Kamehameha, Gohan combines his Kamehameha with Goku's, resulting in double the damage" };
}
