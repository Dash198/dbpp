#include "SaveLoad.h"
#include <string>
#include <fstream>
using namespace std;
int SaveLoad::loadFighters()
{
    int count=0;
    ifstream in("CharData.txt");
    string s;
    while (getline(in, s))
        count++;
    count /= 26;
    return count;
}
