#ifndef __ENEMIES_H
#define __ENEMIES_H

#include "items.h"
#include "rng.h"
#include <string>
#include <vector>
#include "abilities.h"
#include "character.h"

using std::string;
using std::vector;

class enemy{
  private:
    string name;
    string desc;
    int hp, mp, def, mdef, spd;
    vector<abilities> vabs;
    vector<item> drops;
    
  public:
    enemy(string, int, int, int, int, int, string, vector<abilities>, vector<item>);
    string NAME();
    string DESC();
    int HP();
    int MP();
    int DEF();
    int MDEF();
    int SPD();
    void useAbOn(character &player);
    void dropItem(character &player);
  };
    
#endif
