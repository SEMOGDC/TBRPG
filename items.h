#ifndef __ITEMS_H
#define __ITEMS_H
#include <string>
#include <iostream>
using std::ostream;
enum itemType {WEAPON, HELM, CHEST, LEGS, BOOTS, NECK, RING, CONSUMABLE, EMPTY};

class item{
  private:
    int itemID;
    itemType slot = EMPTY;
    int maxhp=0, maxmp=0, str=0, res=0, intel=0, spd=0, per=0, mag=0, 
        def=0, mdef=0, ilvl=1;
    int hpmod=0, mpmod=0, mindmg=0, maxdmg=0;
    double xpmod=0.0;
    std::string itemDesc = "";
    std::string iName = "";
  
  public:
    item ();
    item (int id, itemType slot, int str, int res, int intel, int spd, int per, 
            int mag, int def, int mdef, double xpmod, int hpmod, int mpmod,
            int mindmg, int maxdmg, int maxhp, int maxmp, std::string itemDesc, int ilvl, std::string iName);
    
    //gets
    int ID() const;
    itemType SLOT() const;
    int MAXHP() const;
    int MAXMP() const;
    int STR() const;
    int RES() const;
    int INT() const;
    int SPD() const;
    int PER() const;
    int MAG() const;
    int DEF() const;
    int MDEF() const;
    int HPMOD() const;
    int MPMOD() const;
    int MINDMG() const;
    int MAXDMG() const;
    int ILVL() const;
    double XPMOD() const;
    std::string DESC() const;
    std::string INAME() const;
    void operator=(const item &rhs);
    bool operator==(const item &rhs);
    bool operator!=(const item &rhs);
};
ostream&operator<<(ostream&os, const item& i);
#endif
