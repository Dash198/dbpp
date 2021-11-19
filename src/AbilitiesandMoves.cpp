#include "AbilitiesandMoves.h"

vector<double> AbilitiesandMoves::Effects(string move)
{
    vector<double> effects = { 0,0,0,0,0,0,0,0,0,0 }; //hp, energy drain, att, def, spe, acc, opp att, opp def, opp spe, opp acc
    vector<string> abilities = { "Kaioken","Solar Flare","Zenkai","Great Ape","Ki Charge","Regeneration","Fusion with Kami","Zanzouken","Telepathy" };
    int i = 0;
    while(i<abilities.size()){
        if (abilities[i] == move)
            break;
        i++;
    }
    switch (i) {
    case 0:
        effects[1] = 5;
        effects[2] = 5;
        effects[3] = 5;
        effects[4] = 5;
        effects[5] = 5;
        break;
    case 1:
        effects[9] = 5;
        effects[8] = 5;
        effects[7] = 10;
        break;
    case 2:
        effects[0] = 0.5;
        effects[2] = 20;
        effects[3] = 20;
        effects[4] = 10;
        effects[5] = 10;
        break;
    case 3:
        effects[2] = 25;
        effects[3] = 25;
        effects[4] = -5;
        effects[5] = -10;
        break;
    case 4:
        effects[1] = -20;
        break;
    case 5:
        effects[0] = -20;
        break;
    case 6:
        effects[0] = -40;
        effects[1] = 10;
        effects[2] = 40;
        effects[3] = 40;
        effects[4] = 10;
        effects[5] = 4;
        break;
    case 7:
        effects[4] = 10;
        break;
    case 8:
        effects[9] = 6;
        effects[8] = 5;
        effects[7] = 15;
        break;
    }
    return effects;
}
