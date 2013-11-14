#ifndef __CHARACTER_H
#define __CHARACTER_H
#include <string>
#include <vector>
#include "items.h"

extern item empty;
const int INVSIZE = 15;
class character{
  
  private:
  
    std::string charName = "";
    //stats
    int HPcur, HPmax, MPcur, MPmax;
    int str, res, intel, spd, per, mag, def, mdef, xp=0, lvl=1;
    double xpmod = 1.0;
    
    int GHP=0, GMP=0, Gstr=0, Gres=0, Gint=0, Gspd=0, Gper=0, Gmag=0, Gdef=0, Gmdef=0;
    double Gxpmod;
    
    int mindam=0, maxdam=0;
    
    item equipment[7] = {empty, empty, empty, empty, empty, empty, empty};
    item inventory[INVSIZE] = {empty, empty, empty, empty, empty, empty, 
                               empty, empty, empty, empty, empty, empty, 
                               empty, empty, empty};
    
  public:
  
    //Fed stats through character creation.
  character(std::string name, int str, int res, int intel, int spd, int per, int mag);
      
    //gets / sets
    void nameSet(std::string);
    
    int HPCUR();
    int HPMAX();
    int THP();
    int MPCUR();
    int MPMAX();
    int TMP();
    
    std::string CHARNAME();
    
    void modHPMAX(int);
    void modMPMAX(int);
    
    //currently to be used for damage and mp usage etc
    void modHPCUR(int);
    void modMPCUR(int);
    
    int STR();
    int TSTR();
    int RES();
    int TRES();
    int INT();
    int TINT();
    int SPD();
    int TSPD();
    int PER();
    int TPER();
    int MAG();
    int TMAG();
    int MINDAM();
    int MAXDAM();
    
    //if true, setstat. else modstat
    int STRMOD(bool, int);
    int RESMOD(bool, int);
    int INTMOD(bool, int);
    int SPDMOD(bool, int);
    int PERMOD(bool, int);
    int MAGMOD(bool, int);
    
    //inventory and management
    
    void fullInv();
    void toInv(item);
    
    //calculations
    int damageCalc(int);
    bool hitCalc(int);
    void equip(item);
    void statCalc();
  };
#endif
