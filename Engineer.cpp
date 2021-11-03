/*Title: Engineer.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines an engineer zombie in Plants vs Zombies: Battle for Neighborville
*/

#include "Engineer.h"

const int SPECIAL_DAMAGE = 2;

//Engineer()
//default Constructor
Engineer::Engineer(): Zombie(){}

//Engineer(string, int)
//overloaded Constructor
Engineer::Engineer(string name, int hp): Zombie(name, hp){}

//SpecialAttack
//returns damage from special attack
int Engineer::SpecialAttack(){
  cout << GetName() << " blasts you with their steam blaster!" << endl;
  cout << GetName() << " deals " << SPECIAL_DAMAGE << " points of damage!" << endl;
  return SPECIAL_DAMAGE;
}

