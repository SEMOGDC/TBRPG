#include "character.h"
#include "rng.h"
#include "items.h"
#include <iostream>
extern const int INVSIZE;


//stats
character::character(std::string name, int str, int res, int intel, int spd, int per, int mag){
  xp = 0; lvl = 1;
  
  this->charName = name;
  this->str = str;
  this->res = res;
  this->intel = intel;
  this->spd = spd;
  this->per = per;
  this->mag = mag;
  
  HPmax = str * 1.5;
  HPcur = HPmax;
  
  MPmax = mag * 2;
  MPcur = MPmax;
  
  def = res * 0.8;
  mdef = intel * 0.8;
  mindam = 1;
  maxdam = 4;
}

//GETS AND SETS

void character::nameSet(std::string name){
  this->charName = name;
}


//hp/mp
int character::HPCUR(){return HPcur;}
int character::HPMAX(){return HPmax;}
int character::MPCUR(){return MPcur;}
int character::MPMAX(){return MPmax;}
int character::THP(){return HPmax+GHP;}
int character::TMP(){return HPmax+GMP;}

std::string character::CHARNAME(){return charName;}

void character::modHPMAX(int mod){HPmax += mod;}
void character::modMPMAX(int mod){MPmax += mod;}

//currently to be used for damage and mp usage etc
void character::modHPCUR(int mod){
  HPcur += mod;
  if(HPcur > this->THP())
    HPcur = this->THP();
}

void character::modMPCUR(int mod){
  MPcur += mod;
  if(MPcur > this->TMP())
    MPcur = this->TMP();
}

//stats
int character::STR(){return str;}
int character::RES(){return res;}
int character::INT(){return intel;}
int character::SPD(){return spd;}
int character::PER(){return per;}
int character::MAG(){return mag;}
int character::TSTR(){return str+Gstr;}
int character::TRES(){return res+Gres;}
int character::TINT(){return intel+Gint;}
int character::TSPD(){return spd+Gspd;}
int character::TPER(){return per+Gper;}
int character::TMAG(){return mag+Gmag;}
int character::MINDAM(){return mindam;}
int character::MAXDAM(){return maxdam;}

//stat sets: set=true, else mod

int character::STRMOD(bool set, int mod){
  if(set)
    str = mod;
  else
    str += mod;
  if(HPcur > THP())
    HPcur = THP();
}

int character::RESMOD(bool set, int mod){
  if(set)
    res = mod;
  else
    res += mod;
}

int character::INTMOD(bool set, int mod){
  if(set)
    intel = mod;
  else
    intel += mod;
  if(MPcur > TMP())
    MPcur = TMP();
}

int character::SPDMOD(bool set, int mod){
  if(set)
    spd = mod;
  else
    spd += mod;
}

int character::PERMOD(bool set, int mod){
  if(set)
    per = mod;
  else
    per += mod;
}

int character::MAGMOD(bool set, int mod){
  if(set)
    mag = mod;
  else
    mag += mod;
}

//ITEM/EQUIPMENT BLOCK
void character::fullInv(){
  for(int i = 0; i < INVSIZE; i++){
    std::cout << i+1 << ". " << inventory[i] << std::endl;
  }
}

//equipping gear
void character::equip(item gear){
  item replaced;
  
  switch (gear.SLOT()){
    case WEAPON:
      replaced = equipment[0];
      equipment[0] = gear;
      if(replaced != empty)
        toInv(replaced);
      break;
    case HELM:
      replaced = equipment[1];
      equipment[1] = gear;
      if(replaced != empty)
        toInv(replaced);
      break;
    case CHEST:
      replaced = equipment[2];
      equipment[2] = gear;
      if(replaced != empty)
        toInv(replaced);
      break;
    case LEGS: 
      replaced = equipment[3];
      equipment[3] = gear;
      if(replaced != empty)
        toInv(replaced);
      break;
    case BOOTS:
      replaced = equipment[4];
      equipment[4] = gear;
      if(replaced != empty)
        toInv(replaced);
      break;
    case NECK: 
      replaced = equipment[5];
      equipment[5] = gear;
      if(replaced != empty)
        toInv(replaced);
      break;
    case RING: 
      replaced = equipment[6];
      equipment[6] = gear;
      if(replaced != empty)
        toInv(replaced);
      break;
    case CONSUMABLE:
      std::cout << "\nCannot equip consumables.\n";
      toInv(gear);
      break;
    case EMPTY:
      std:: cout << "\nCannot equip empty slot.\n";
      break;
    }
    
statCalc();

}

void character::toInv(item replaced){
    //Place item into first empty inventory slot
  bool invplaced = false;
  int i = 0;
  for(i = 0; i < INVSIZE && invplaced == false; i++){
    if(inventory[i] == empty){
      inventory[i] = replaced;
      invplaced = true;
    }
  }
    if(i>14 && invplaced == false){
      std::cout << "No room in inventory. Discard an item?\n1. Yes\n2. No\n";
      
      int discard = -1;
      
      while(1 > discard || discard > 2)
        std::cin >> discard;
      if(discard > 1)
        ;
      else{
        this->fullInv();
        std::cout << "\nSelect item to discard.\n";
        discard = -1;
        while(1 > discard || discard > 15)
          std::cin >> discard;
        inventory[discard-1] = replaced;
        invplaced = true;
      }
    }
}

//CALCULATION BLOCK
int character::damageCalc(int enemyDef){
  return(((rng(mindam, maxdam)) + (0.4*(str + Gstr))) * (100.0 / (100.0 + enemyDef)));
}

bool character::hitCalc(int enemySpd){
  bool r = false;
  if((rng(1, 100) + spd - enemySpd) > 35)
    r = true;
  return r;
}

void character::statCalc(){
  GHP=0; GMP=0; Gstr=0; Gres=0; Gint=0;
  Gspd=0; Gmag=0; Gdef=0; Gmdef=0; Gxpmod=0.0;
  mindam=0; maxdam=0;
  
  
  for(int i = 0; i < 7; i++){
    GHP += equipment[i].MAXHP();
    GMP += equipment[i].MAXMP();
    Gstr += equipment[i].STR();
    Gres += equipment[i].RES();
    Gint += equipment[i].INT();
    Gspd += equipment[i].SPD();
    Gmag += equipment[i].MAG();
    Gdef += equipment[i].DEF();
    Gmdef += equipment[i].MDEF();
    Gxpmod += equipment[i].XPMOD();
    mindam += equipment[i].MINDMG();
    maxdam += equipment[i].MAXDMG();
  }
  
  if(HPcur > THP())
    HPcur = THP();
  if(MPcur > TMP())
    MPcur = TMP();
  if(maxdam == 0){
    mindam = 1;
    maxdam = 4;
    }
}
