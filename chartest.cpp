//character class test
#include <string>
#include <iostream>
#include "character.h"
#include "enemies.h"
using std::cout;
using std::cin;
using std::string;

int main(int argc, char** argv){
  int a, b, c, d, e, f;
  string input = "";
  
  //character creation test
  cout << "Enter your stats in order: \nSTR\nRES\nINT\nSPD\nPER\nMAG\n";
  cin >> a >> b >> c >> d >> e >> f;
  
  cout << "Enter your character's name.\n";
  cin.clear();
  cin.ignore(60, '\n');
  std::getline(cin, input);
  character PLAYER(input, a, b, c, d, e, f);
  
  //player info output test
  cout << "\n\nPLAYER INFO:\n Name: " << PLAYER.CHARNAME() << "\nStats:\n";
  cout << "  Str: " << PLAYER.STR() << "\n  Res: " << PLAYER.RES();
  cout << "\n  Int: " << PLAYER.INT() << "\n  Spd: " << PLAYER.SPD();
  cout << "\n  Per: " << PLAYER.PER() << "\n  Mag: " << PLAYER.MAG();
  
  cout << "\n   HP: " << PLAYER.HPCUR() << "/" << PLAYER.HPMAX();
  cout << "\n   MP: " << PLAYER.MPCUR() << "/" << PLAYER.MPMAX() << '\n';
  
  system("pause");
  //hp damage test
  cout << "\nHoly shit, you just took two damage!\n";
  
  PLAYER.modHPCUR(-2);
  cout << "\n HP: " << PLAYER.HPCUR() << "/" << PLAYER.HPMAX();
  
  cout << "\nAnd now something's fucking with your stats...\n\n";
  
  //setstat test
  PLAYER.STRMOD(1, 20);
  PLAYER.INTMOD(0, -3);
  PLAYER.SPDMOD(0, 45);
  PLAYER.MAGMOD(1, 1);
  
  cout << "  Str: " << PLAYER.STR() << "\n  Res: " << PLAYER.RES();
  cout << "\n  Int: " << PLAYER.INT() << "\n  Spd: " << PLAYER.SPD();
  cout << "\n  Per: " << PLAYER.PER() << "\n  Mag: " << PLAYER.MAG() << '\n';
  
  system("pause");
  //hit and damage calculation test
  cout << "\n\nMaking an attack against an enemy with 0 defense.\n";
  
  cout << "\nYou attempt to swing! The enemy's speed is 5.\n";
  
  if(PLAYER.hitCalc(5))
    cout << "You deal " << PLAYER.damageCalc(0) << " damage to it!\n";
  else
    cout << "You miss!\n";
    
  cout << "This enemy has 100 def and 50 spd.\n";
  
  if(PLAYER.hitCalc(50))
    cout << "You deal " << PLAYER.damageCalc(100) << " damage to it!\n";
  else
    cout << "You miss like a bitch!\n";
   
  system("pause");
  //item generation test
  cout << "\nGenerating and equipping test item.\n";
  
    item gs(0, CHEST, 6, 6, 6, 6, 6, 6, 10, 10, 1.5, 0, 0, 15, 25, 30, 20,
                 "Test Description", 20, "testItem");
    item gs2(0, CHEST, 6, 6, 6, 6, 6, 6, 10, 10, 1.5, 0, 0, 15, 25, 30, 20,
                 "Test Description", 20, "discItem");
    item gs3(0, WEAPON, 6, 6, 6, 6, 6, 6, 10, 10, 1.5, 0, 0, 15, 25, 30, 20,
                 "Test Description", 20, "discItem");
    item gs4(0, NECK, 6, 6, 6, 6, 6, 6, 10, 10, 1.5, 0, 0, 15, 25, 30, 20,
                 "Test Description", 20, "discItem");
  //equip and inventory overflow test
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs);
  PLAYER.equip(gs2); //item to be replaced by gs
  PLAYER.equip(gs);  //shoves gs2 into inventory
  
  PLAYER.equip(gs3);
  PLAYER.equip(gs4);
  
  //equipment stat modification test
  cout << "Outputting new stats with weapon: ";
 cout << "\n\nPLAYER INFO:\n Name: " << PLAYER.CHARNAME() << "\nStats:\n";
  cout << "  Str: " << PLAYER.TSTR() << "\n  Res: " << PLAYER.TRES();
  cout << "\n  Int: " << PLAYER.TINT() << "\n  Spd: " << PLAYER.TSPD();
  cout << "\n  Per: " << PLAYER.TPER() << "\n  Mag: " << PLAYER.TMAG();
  
  cout << "\n   HP: " << PLAYER.HPCUR() << "/" << PLAYER.THP();
  cout << "\n   MP: " << PLAYER.MPCUR() << "/" << PLAYER.TMP();
  
  cout << "\nYour damage range: " << PLAYER.MINDAM() << "-" << PLAYER.MAXDAM() << "\n";
  
  //inventory output test
  PLAYER.fullInv();
  
  system("pause");
  //enemy and ability creation test
  string d1 = "touches your booty!", d2 = "stabs you!", d3 = "Kicks you!";
  string d4 = "OTHER MOVE";
  vector<string> descs, desc2;
  vector<item> drops;
  
  descs.push_back(d1);
  descs.push_back(d2);
  descs.push_back(d3);
  desc2.push_back(d4);
  
  drops.push_back(gs2);
  drops.push_back(gs3);
  drops.push_back(gs4);
  
  abilities ab1("Basic attack", 2, 4, 0, 0, descs);
  abilities ab2("Other attack", 3, 5, -1, -1, desc2);
  
  vector<abilities> vabs;
  vabs.push_back(ab1);
  vabs.push_back(ab2);
  
  cout << "\n\n\nEnemy test: Creating an enemy.\n";
  enemy tmon("Tmon", 50, 50, 50, 50, 35, "A monster of testing trials.", vabs, drops);
  cout << "Enemy info:\nName:" << tmon.NAME() << "\nHP: " << tmon.HP() <<
          "\nMP: " << tmon.MP() << "\nDef: " << tmon.DEF() << "\nMdef: " << tmon.MDEF()
          << "\nspd: " << tmon.SPD() << "\nDescription: " << tmon.DESC();
  
  //enemy attack test
  PLAYER.modHPCUR(100);
  cout << "\n\nPlayer HP: " << PLAYER.HPCUR() << "/" << PLAYER.THP();
  
  cout << "\n\nTestmonst making 3 attacks against player.\n";
  tmon.useAbOn(PLAYER);  
  tmon.useAbOn(PLAYER);
  tmon.useAbOn(PLAYER);
  cout << "\n\nPlayer HP: " << PLAYER.HPCUR() << "/" << PLAYER.THP() << '\n';
 
  system("pause");
 
  //item drop test 
  cout << "\n\nIt suddenly died! It drops an item!\n";
  tmon.dropItem(PLAYER);

  PLAYER.fullInv();  
}
