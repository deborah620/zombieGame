/***********************************************************
 ** File:    Entity.cpp
 ** Project: Plants vs Zombies: Battle for Neighborville
 ** Author: Deborah Miller
 ** Date     10/29/2020
 ** Section: 10/14
 ** This file contains the .cpp file of the Entity class
 **********************************************************/

#include "Entity.h"

//Entity()
//default Constructor
Entity::Entity(){
  m_name = "default";
  m_health = 1;
}

//Entity(string, int)
//overloaded constructor
Entity::Entity(string name, int health){
  m_name = name;
  m_health = health;
}

//virtual ~Entity
//virtual Destructor
Entity::~Entity(){
  m_name = "";
  m_health = 0;
}

//GetName()
//returns name of entity
string Entity::GetName(){
  return m_name;
}

//GetHealth()
//returns health of entity
int Entity::GetHealth(){
  return m_health;
}

//SetName()
//sets name of entity
void Entity::SetName(string name){
  m_name = name;
}

//SetHealth()
//sets health of entity
void Entity::SetHealth(int health){
  m_health = health;
}

//Overloaded <<
//prints the details of an entity
ostream& operator<<(ostream &output, Entity &myEntity){
  output << "Name: " << myEntity.GetName() << endl << "HP: " << myEntity.GetHealth();
  return output;
}
