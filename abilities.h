#ifndef __ABILITIES_H
#define __ABILITIES_H

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class abilities{
  private: 
    string name;
    int minDmg, maxDmg, mpCost, hpCost;
    vector<string>atkDesc;
    
  public:
    abilities(string, int, int, int, int, vector<string>);
    
    //Gets
    string NAME(){return name;}
    int MINDMG(){return minDmg;}
    int MAXDMG(){return maxDmg;}
    int MPCOST(){return mpCost;}
    int HPCOST(){return hpCost;}
    string DESC();
};
#endif
