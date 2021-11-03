/*Title: Chomper.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines a chomper plant/player in Plants vs Zombies: Battle for Neighborville
*/

#include "Chomper.h"

const int MAX = 12; //used in rand(), max damage can do 
const int MIN = 2; //used in rand(), min damage can do

//Chomper()
//default Constructor
Chomper::Chomper(): Plant(){}

//Chomper(string, int)
//overloaded Constructor
Chomper::Chomper(string name, int hp): Plant(name, hp) {}

//~Chomper
//virtual Destructor
Chomper::~Chomper(){
}

//SpecialAttack
//returns damage from special attack
int Chomper::SpecialAttack() {
  int randomNum = (rand() % (MAX + 1 - MIN)) + MIN;
  cout << GetName() << " performs a sneak attack! CHOMP" << endl;
  cout << GetName() << " attacks dealing " << randomNum << " damage" << endl;
  return randomNum;
}


