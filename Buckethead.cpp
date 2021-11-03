/*Title: Buckethead.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines a buckethead zombie in Plants vs Zombies: Battle for Neighborville
*/

#include "Buckethead.h"

const int SPECIAL_DAMAGE = 1;

//Buckethead()
//default Constructor
Buckethead::Buckethead():Zombie(){}

//Buckethead(string, int)
//overloaded Constructor
Buckethead::Buckethead(string name, int hp):Zombie(name, hp){}

//SpecialAttack
//returns damage from special attack
int Buckethead::SpecialAttack(){
  cout << GetName() << " throws its bucket at you!" << endl;
  cout << GetName() << " deals " << SPECIAL_DAMAGE << " points of damage!" << endl;
  return SPECIAL_DAMAGE;
}
