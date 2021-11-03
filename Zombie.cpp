/*Title: Zombie.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines a zombie in Plants vs Zombies: Battle for Neighborville
*/

#include "Zombie.h"

const int ZOMBIE_DAMAGE = 1;

//Zombie()
//default Constructor
Zombie::Zombie(): Entity() {}

//Zombie(string, int)
//overloaded Constructor
Zombie::Zombie(string name, int hp): Entity(name, hp){}

//Attack()
//returns damage
int Zombie::Attack(){
  cout << GetName() << " deals " << ZOMBIE_DAMAGE << " point of damage!" << endl;
  return ZOMBIE_DAMAGE;
}

