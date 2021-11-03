/*Title: Sunflower.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines a sunflower plant/player in Plants vs Zombies: Battle for Neighborville
*/

#include "Sunflower.h"

const int MAX = 8; //used in rand(), max damage can do
const int MIN = 1; //used in rand(), min damage can do

//Sunflower()
//default Constructor
Sunflower::Sunflower(): Plant(){}

//Sunflower(string, int)
//overloaded Constructor
Sunflower::Sunflower(string name, int hp): Plant(name, hp) {}

//~Sunflower
//virtual Destructor
Sunflower::~Sunflower(){
}

//SpecialAttack
//returns damage from special attack
int Sunflower::SpecialAttack() {
  int randomNum = (rand() % (MAX + 1 - MIN)) + MIN;
  cout << GetName() << " uses a high beam turret - *SUNBEAM*" << endl;
  cout << GetName() << " attacks dealing " << randomNum << " damage" << endl;
  return randomNum;
}


