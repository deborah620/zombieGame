/*Title: Peashooter.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines a peashooter plant/player in Plants vs Zombies: Battle for Neighborville
*/

#include "Peashooter.h"

const int MAX = 12; //used in rand(), max damage can do
const int MIN = 3; //used in rand(), min damage can do

//Peashooter()
//default Constructor
Peashooter::Peashooter(): Plant(){}

//Peashooter(string, int)
//overloaded Constructor
Peashooter::Peashooter(string name, int hp): Plant(name, hp) {}

//~Peashooter
//virtual Destructor
Peashooter::~Peashooter(){
}

//SpecialAttack
//returns damage from special attack
int Peashooter::SpecialAttack() {
  int randomNum = (rand() % (MAX + 1 - MIN)) + MIN;
  cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
  cout << GetName() << " attacks dealing " << randomNum << " damage" << endl;
  return randomNum;
}


