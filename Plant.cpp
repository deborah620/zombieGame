/*Title: Plant.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines a plant/player in Plants vs Zombies: Battle for Neighborville
*/

#include "Plant.h"

const int MAX = 6; //used in rand(), max damage can do
const int MIN = 1; //used in rand(), min damage can do

//Plant()
//default Constructor
Plant::Plant(): Entity() {}

//Plant(string, int)
//overloaded constructor
Plant::Plant(string name, int hp): Entity(name, hp) {}

//~Plant
//virtual Destructor
Plant::~Plant(){
}

//Attack()
//returns damage
int Plant::Attack(){
  int randomNum = (rand() % (MAX + 1 - MIN)) + MIN;
  cout << GetName() << " attacks dealing " << randomNum << " damage" << endl;
  return randomNum;
}

//SpecialAttack()
//tells player that plant does not have special attack
//can also call child class SpecialAttack
int Plant::SpecialAttack(){
  cout << GetName() << " doesn't have a Special Attack :(" << endl;
  return 0;
}
