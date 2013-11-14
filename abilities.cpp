#include "abilities.h"
#include "rng.h"

using std::string;
abilities::abilities(string name, int minDmg, int maxDmg, int mpCost, int hpCost, vector<string> atkDesc){
  this -> name = name;
  this -> minDmg = minDmg;
  this -> maxDmg = maxDmg;
  this -> mpCost = mpCost;
  this -> hpCost = hpCost;
  this -> atkDesc = atkDesc;
}

string abilities::DESC(){
  return atkDesc[rng(0, atkDesc.size()-1)];
}
