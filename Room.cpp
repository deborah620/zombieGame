/*Title: Room.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines rooms in Plants vs Zombies: Battle for Neighborville
*/

#include "Room.h"

//Room(int, string, string, int, int, int, int)
//Overloaded Constructor, creates a new room
Room::Room(int id, string name, string desc, int north, int east, int south, int west){
  m_ID = id;
  m_name = name;
  m_desc = desc;
  
  m_direction[N] = north;
  m_direction[E] = east;
  m_direction[S] = south;
  m_direction[W] = west;
}

//GetName()//
//returns room name
string Room::GetName(){
  return m_name;
}

//GetID()
//returns room id
int Room::GetID(){
  return m_ID;
}

//GetDesc()
//returns room desc
string Room::GetDesc(){
  return m_desc;
}

//CheckDirection(char)
//returns the ID of the room in that direction
//If there is no exit in that direction, returns -1
int Room::CheckDirection(char myDirection){
  int desiredDirection;
      
  switch(myDirection){
  case 'N':
  case 'n':
    desiredDirection = N;
    break;
  case 'S':
  case 's':
    desiredDirection = S;
    break;
  case 'E':
  case 'e':
    desiredDirection = E;
    break;
  case 'W':
  case 'w':
    desiredDirection = W;
    break;
  }
    
  if(m_direction[desiredDirection] != -1){
    return m_direction[desiredDirection];
  }
  return -1;
}

//PrintRoom()
//outputs the room name, room desc, and possible exits
void Room::PrintRoom(){
  cout << m_name << endl;

  cout << m_desc << endl;

  cout << "Possible Exits: " ;
  if(m_direction[N] != -1)
    cout << "N ";
  if(m_direction[E] != -1)
    cout << "E ";
  if(m_direction[S] != -1)
    cout << "S ";
  if(m_direction[W] != -1)
    cout << "W ";
  
  cout << endl;
}  
