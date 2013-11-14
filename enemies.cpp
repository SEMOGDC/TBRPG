#include "enemies.h"
#include "abilities.h"
using std::cout;
enemy::enemy(string name, int hp, int mp, int def, int mdef, int spd, string desc, vector<abilities> vabs, vector<item> drops){
  this->name = name;
  this->hp = hp;
  this->mp = mp;
  this->def = def;
  this->mdef = mdef;
  this->spd = spd;
  this->desc = desc;
  this->vabs = vabs;
  this->drops = drops;
}

  string enemy::NAME(){return name;}
  string enemy::DESC(){return desc;}
  int enemy::HP(){return hp;}
  int enemy::MP(){return mp;}
  int enemy::DEF(){return def;}
  int enemy::MDEF(){return mdef;}
  int enemy::SPD(){return spd;}
  
  void enemy::dropItem(character &player){
    int drop = rng(0, drops.size()-1);
    player.toInv(drops[drop]);
  }
  
  void enemy::useAbOn(character &player){
    abilities use = vabs[rng(0, vabs.size()-1)];
    hp -= use.HPCOST();
    mp -= use.MPCOST();
    cout << "\nXXX Player HPCUR: " << player.HPCUR() << "\n";
    int dmgDealt = rng(use.MINDMG(), use.MAXDMG());
    std::cout << name << " " << use.DESC() << " It deals " << dmgDealt << " damage!\n";
    if(use.HPCOST() < 0)
      cout << name << " regenerates from its wounds!\n";
    if(use.MPCOST() < 0)
      cout << name << " brims with magical energy!\n";
    player.modHPCUR(0-dmgDealt);
}
