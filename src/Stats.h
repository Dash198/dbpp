#pragma once
#include <string>
#include <vector>
using namespace std;
class Stats
{
public:
	double hp, thp;
	string name;
	vector<string> moves;
	vector<double> moved;
	int energy;
	vector<int> energycost;
	vector<string> movedesc;
	vector<double> accuracy;
	double attack, defense, speed;
	Stats();
};

