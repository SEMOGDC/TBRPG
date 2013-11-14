#include "items.h"
#include <vector>
#include <iostream>
using std::ostream;
using std::cout;
using std::vector;
vector<item> itemIndex;

item::item(){
  itemID = 0;
  slot = EMPTY;
  str = 0; res = 0; intel = 0; spd = 0; per = 0; mag = 0;
  def = 0; mdef = 0; xpmod = 0.0; hpmod = 0; mpmod = 0;
  mindmg = 0; maxdmg = 0; maxhp = 0; maxmp = 0; itemDesc = "";
  ilvl = 0;
  iName = "";
}

item::item (int id, itemType slot, int str, int res, int intel, int spd, int per, 
        int mag, int def, int mdef, double xpmod, int hpmod, int mpmod,
        int mindmg, int maxdmg, int maxhp, int maxmp, std::string itemDesc, int ilvl,
        std::string iName){
  this->itemID = id;
  this->slot = slot;
  this->str = str;
  this->res = res;
  this->intel = intel;
  this->spd = spd;
  this->per = per;
  this->mag = mag;
  this->def = def;
  this->mdef = mdef;
  this->xpmod = xpmod;
  this->hpmod = hpmod;
  this->mpmod = mpmod;
  this->mindmg = mindmg;
  this->maxdmg = maxdmg;
  this->maxhp = maxhp;
  this->maxmp = maxmp;
  this->itemDesc = itemDesc;
  this->ilvl = ilvl;
  this->iName = iName;
}


item empty(0, EMPTY, 0,0,0,0,0,0,0,0,0.0,0,0,0,0,0,0,"Empty Slot", 0, "<empty>");


int item::ID() const{return itemID;}
itemType item::SLOT() const{return slot;}
int item::MAXHP() const{return maxhp;}
int item::MAXMP() const{return maxmp;}
int item::STR() const{return str;}
int item::RES() const{return res;}
int item::INT() const{return intel;}
int item::SPD() const{return spd;}
int item::PER() const{return per;}
int item::MAG() const{return mag;}
int item::DEF() const{return def;}
int item::MDEF() const{return mdef;}
int item::HPMOD() const{return hpmod;}
int item::MPMOD() const{return mpmod;}
int item::MINDMG() const{return mindmg;}
int item::MAXDMG() const{return maxdmg;}
int item::ILVL() const{return ilvl;}
double item::XPMOD() const{return xpmod;}
std::string item::DESC() const{return itemDesc;}
std::string item::INAME() const{return iName;}


void item::operator=(const item &rhs){
  itemID = rhs.ID();
  slot = rhs.SLOT();
  str = rhs.STR();
  res = rhs.RES();
  intel = rhs.INT();
  spd = rhs.SPD();
  per = rhs.PER();
  mag = rhs.MAG();
  def = rhs.DEF();
  mdef = rhs.MDEF();
  xpmod = rhs.XPMOD();
  hpmod = rhs.HPMOD();
  mpmod = rhs.MPMOD();
  mindmg = rhs.MINDMG();
  maxdmg = rhs.MAXDMG();
  maxhp = rhs.MAXHP();
  maxmp = rhs.MAXMP();
  itemDesc = rhs.DESC();
  ilvl = rhs.ILVL();  
  iName = rhs.INAME();
}

bool item::operator==(const item &rhs){
  bool r = false;
  if(
  itemID == rhs.ID() &&
  slot == rhs.SLOT() &&
  str == rhs.STR() &&
  res == rhs.RES() &&
  intel == rhs.INT() &&
  spd == rhs.SPD() &&
  per == rhs.PER() &&
  mag == rhs.MAG() &&
  def == rhs.DEF() &&
  mdef == rhs.MDEF() &&
  xpmod == rhs.XPMOD() &&
  hpmod == rhs.HPMOD() &&
  mpmod == rhs.MPMOD() &&
  mindmg == rhs.MINDMG() &&
  maxdmg == rhs.MAXDMG() &&
  maxhp == rhs.MAXHP() &&
  maxmp == rhs.MAXMP() &&
  itemDesc == rhs.DESC() &&
  ilvl == rhs.ILVL() &&
  iName == rhs.INAME()
  )
  r = true;
  return r;
}

bool item::operator!=(const item &rhs){
  bool r = false;
  if(
  itemID != rhs.ID() ||
  slot != rhs.SLOT() ||
  str != rhs.STR() ||
  res != rhs.RES() ||
  intel != rhs.INT() ||
  spd != rhs.SPD() ||
  per != rhs.PER() ||
  mag != rhs.MAG() ||
  def != rhs.DEF() ||
  mdef != rhs.MDEF() ||
  xpmod != rhs.XPMOD() ||
  hpmod != rhs.HPMOD() ||
  mpmod != rhs.MPMOD() ||
  mindmg != rhs.MINDMG() ||
  maxdmg != rhs.MAXDMG() ||
  maxhp != rhs.MAXHP() ||
  maxmp != rhs.MAXMP() ||
  itemDesc != rhs.DESC() ||
  ilvl != rhs.ILVL() ||
  iName != rhs.INAME()
  )
  r = true;
  return r;
}

ostream&operator<<(ostream& os, const item& i){
  cout << i.INAME();
  return os;
}
