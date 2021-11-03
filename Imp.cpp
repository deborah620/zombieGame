/*Title: Imp.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines an imp zombie in Plants vs Zombies: Battle for Neighborville
*/

#include "Imp.h"

const int SPECIAL_DAMAGE = 4;

//Imp()
//default Constructor
Imp::Imp(): Zombie(){}

//Imp(string, int)
//overloaded Constructor
Imp::Imp(string name, int hp): Zombie(name, hp){}

//SpecialAttack
//returns damage from special attack
int Imp::SpecialAttack(){
  cout << GetName() << " blasts you with their Impkata attack!" << endl;
  cout << GetName() << " deals " << SPECIAL_DAMAGE << " points of damage!" << endl;
  return SPECIAL_DAMAGE;
}

