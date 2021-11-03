/*Title: Game.cpp
Author: Deborah Miller
Email: d169@umbc.edu
Section: 10/14
Date: 10/29/2020
Description: This class defines the main game play in Plants vs Zombies: Battle for Neighborville
*/

#include "Game.h"

const int MAX = 100; //used for rand() parameters
const int MIN = 1; //used for rand() parameters
const int PERCENT_CHANCE = 25; //25% chance no Zombie and of Zombie special attack

// Game()
// Default Constructor
Game::Game(){
  string fileName;

  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  
  cout << "Please enter a file name: ";
  cin >> fileName;
  LoadMap(fileName);
  PlantCreation();
}

//Game(string)
// Overloaded Constructor
Game::Game(string fileName){
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  LoadMap(fileName);
  PlantCreation();
}

//~Game()
//Destructor
Game::~Game(){
  for (unsigned int i = 0; i < m_myMap.size(); i++) {
    delete m_myMap.at(i);
  }
  for (unsigned int i = 0; i < m_myMap.size(); i++) {
    m_myMap.erase(m_myMap.begin() + i);
  }

  delete m_myPlant;
  delete m_curZombie;

  m_myPlant = nullptr;
  m_curZombie = nullptr;
}

//LoadMap(string)
// Dynamically creates rooms and inserts them into the m_myMap vector
void Game::LoadMap(string fileName){
  string id;
  string name;
  string desc;
  string n;
  string e;
  string s;
  string w;
  
  ifstream mapFile(fileName);

  if (mapFile.is_open()){
    while (getline(mapFile, id, '|')) {
      getline(mapFile, name, '|');
      getline(mapFile, desc, '|');
      getline(mapFile, n, '|');
      getline(mapFile, e, '|');
      getline(mapFile, s, '|');
      getline(mapFile, w);
   
      m_myMap.push_back(new Room(stoi(id), name, desc, stoi(n), stoi(e), stoi(s), stoi(w)));
    }
  }
  
  else{
    cout << "file doesn't exist" << endl;
  }
  mapFile.close();
}

//PlantCreation()
//user creates a new plant to play as
//              either plant, sunflower, chomper, or peashooter.
void Game::PlantCreation(){
  string plantName;
  int option;

  cout << "Welcome to UMBC Adventure!" << endl;
  
  cout << "Plant Name: ";
  cin >> plantName;
  cout << endl;

  cout << "Select a class\n"
                    "1. Peashooter \n"
                    "2. Chomper \n"
                    "3. Sunflower \n"
    "4. No Class \n";

  cin >> option;

  //validating input
  while(option > 4 || option < 1){
    cout << "invalid option" << endl;
    cout << "Select a class\n"
                      "1. Peashooter \n"
                      "2. Chomper \n"
                      "3. Sunflower \n"
      "4. No Class \n";
    cin >> option;
  }

  switch(option) {
  case 1:
    m_myPlant = new Peashooter(plantName, PEASHOOTER_HEALTH);
    break;
  case 2:
    m_myPlant = new Chomper(plantName, CHOMPER_HEALTH);
    break;
  case 3:
    m_myPlant = new Sunflower(plantName, SUNFLOWER_HEALTH);
    break;
  case 4:
    m_myPlant = new Plant(plantName, PLANT_HEALTH);
    break;
  default:
    break;
  }
  StartGame();
}

//StartGame()
//current room is set (0 by default) and Action is called
void Game::StartGame(){
  m_curRoom = START_ROOM;
  cout << endl;
  m_myMap.at(m_curRoom)->PrintRoom();

  m_curZombie = RandomZombie();
  
  Action();
}

//Action()
//menu for game, continues until quit or player dies
void Game::Action() {
  int option = 0;
  
  while(option != 6 && (m_myPlant->GetHealth() > 0)) {
    cout << "What would you like to do?\n"
                      "1. Look\n"
                      "2. Move\n"
                      "3. Attack Zombie\n"
                      "4. Rest\n"
                      "5. Check Stats\n"
                      "6. Quit\n";
    cin >> option;

    //validating input
    while (option < 1 || option > 6) {
      cout << "invalid options" << endl;
      cout << "What would you like to do?\n"
	                    "1. Look\n"
	                    "2. Move\n"
	                    "3. Attack Zombie\n"
	                    "4. Rest\n"
	                    "5. Check Stats\n"
	                    "6. Quit\n";
      cin >> option;
    }

    switch (option) {
    case 1:
      m_myMap.at(m_curRoom)->PrintRoom();
      break;
    case 2:
      Move();
      break;
    case 3:
      Attack();
      break;
    case 4:
      Rest();
      break;
    case 5:
      Stats();
      break;
    case 6:
      break;
    default:
      break;
    }
  }
  cout << "Goodbye!" << endl;
}

//RandomZombie()
//randomly creates a dynamically allocated zombie
//              of Buckethead, Imp, or Engineer
//              25% chance no Zombie is created 
Entity* Game::RandomZombie(){
  int randomNum = (rand() % (MAX + 1 - MIN)) + MIN;

  //25% chance of each thing happening
  if(randomNum <= PERCENT_CHANCE) {
    m_curZombie = new Buckethead("Buckethead", BUCKETHEAD_HEALTH);
    cout << "A buckethead zombie teaters here with a bucket on his head." << endl;
  }
  else if(randomNum > PERCENT_CHANCE && randomNum <= (PERCENT_CHANCE * 2)) {
    m_curZombie = new Engineer("Engineer", ENGINEER_HEALTH);
    cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER" << endl;
  }
  else if(randomNum > (PERCENT_CHANCE * 2) && randomNum <= (PERCENT_CHANCE * 3)) {
    m_curZombie = new Imp("Imp", IMP_HEALTH);
    cout << "A dirty imp licks his lips and glares at you." << endl;
  }
  else if(randomNum > (PERCENT_CHANCE * 3)){
    cout << "It's peaceful in here." << endl;
    m_curZombie = nullptr;
  }
  return m_curZombie;
}

//Rest()
//if no zombies in current room, allows player to rest
void Game::Rest(){
  if(!m_curZombie && m_numRests > 0){
    cout << "You rest and wake up refreshed" << endl;
    m_numRests--;
    m_myPlant->SetHealth(m_myPlant->GetHealth() + REST_HEAL);
  }
  else if(m_numRests <= 0)
    cout << "You have no rests left" << endl;
  else
    cout << "You cannot rest with a zombie in the room." << endl;
}

//Move()
//moves a player from one room to another (updates m_curRoom)
void Game::Move(){
  char direction;
  int check;
  
  cout << "Which direction? (N E S W)" << endl;
  cin >> direction;

  //validating input
  while(toupper(direction) != 'N' && toupper(direction) != 'E' && toupper(direction) != 'S' && toupper(direction) != 'W'){
    cout << "please input a valid direction" << endl;
    cout << "Which direction? (N E S W)" << endl;
    cin >> direction;
  }
  
  //checks if there's a room in desired direction
  check = m_myMap.at(m_curRoom)->CheckDirection(direction);
  if(check != -1){
    m_curRoom = check;
    cout << endl;
    m_myMap.at(m_curRoom)->PrintRoom();

    //delete Zombie and reallocate Zombie when move rooms
    delete m_curZombie;
    m_curZombie = nullptr;
    m_curZombie = RandomZombie();  
  }
  
  else{
    cout << "no exit that way" << endl;
    cout << endl;
    m_myMap.at(m_curRoom)->PrintRoom();
  }
}


//Attack()
//player attacks a zombie
void Game::Attack(){
  if(!m_curZombie)
    cout << "no zombies to attack" << endl;
  else{
    bool plantDestroyed = false;
    bool zombieDestroyed = false;
    
    while(!plantDestroyed && !zombieDestroyed){
      int option = 0;
      //validate input
      while (option != 1 && option != 2) {
	cout << "1. Normal Attack\n"
	  "2. Special Attack\n";
	cin >> option;
      }
      //normal attack
      if(option == 1){
	int plantDamage;
	int zombieDamage;

	//player attacks Zombie
	plantDamage = m_myPlant->Attack();
	m_curZombie->SetHealth(m_curZombie->GetHealth() - plantDamage);
	if(m_curZombie->GetHealth() <= 0)
	  zombieDestroyed = true;

	//if Zombie hasn't been killed, its his turn
	else{
	  //Zombie has a 25% chance of doing a special attack 
	  int randomNum = (rand() % (MAX + 1 - MIN)) + MIN;
	  if(randomNum <= PERCENT_CHANCE)
	    zombieDamage = m_curZombie->SpecialAttack();
	  else
	    zombieDamage = m_curZombie->Attack();
	  
	  m_myPlant->SetHealth(m_myPlant->GetHealth() - zombieDamage);
	  if(m_myPlant->GetHealth() <= 0)
	    plantDestroyed = true;
	}
	//no negative health
	if(m_myPlant->GetHealth() < 0)
	  m_myPlant->SetHealth(0);
	if(m_curZombie->GetHealth() < 0)
	  m_curZombie->SetHealth(0);
	
	cout << m_myPlant->GetName() << " health: " << m_myPlant->GetHealth() << endl;
	cout << m_curZombie->GetName() << " health: " << m_curZombie->GetHealth() << endl;
      }
      //special attack
      else if(option == 2){
	if (m_numSpecial <= 0)
	  cout << "Sorry, out of special attacks" << endl;

	else {
	  int plantDamage;
	  int zombieDamage;

	  m_numSpecial--;

	  //player attacks
	  plantDamage = m_myPlant->SpecialAttack();

	  //makes sure the player isn't a normal plant
	  if(plantDamage != 0){
	    m_curZombie->SetHealth(m_curZombie->GetHealth() - plantDamage);
	    if(m_curZombie->GetHealth() <= 0)
	      zombieDestroyed = true;

	    //if Zombie is still alive, its his turn
	    else{
	      //Zombie has a 25% chance of doing a special attack
	      int randomNum = (rand() % (MAX + 1 - MIN)) + MIN;
	      if(randomNum <= PERCENT_CHANCE)
		zombieDamage = m_curZombie->SpecialAttack();
	      else
		zombieDamage = m_curZombie->Attack();
	      	    
	      m_myPlant->SetHealth(m_myPlant->GetHealth() - zombieDamage);
	      if(m_myPlant->GetHealth() <= 0)
		plantDestroyed = true;
	    }
	    //no negative health
	    if(m_myPlant->GetHealth() < 0)
	      m_myPlant->SetHealth(0);
	    if(m_curZombie->GetHealth() < 0)
	      m_curZombie->SetHealth(0);
	    
	    cout << m_myPlant->GetName() << " health: " << m_myPlant->GetHealth() << endl;
	    cout << m_curZombie->GetName() << " health: " << m_curZombie->GetHealth() << endl;
	  }
	}
      }
    }
    if(zombieDestroyed){
      cout << "You have defeated the " << m_curZombie->GetName() << "." << endl;
      delete m_curZombie;
      m_curZombie = nullptr;
    }
    //if plant is destroyed, player loses and the game ends
    else if(plantDestroyed)
      cout << "You lose!" << endl;
  }
}

//Stats()
//displays the information about the player (name, hp, rests, specials)
void Game::Stats(){
  cout << *m_myPlant << endl;
  cout << "Rests: " << m_numRests << endl;
  cout << "Special: " << m_numSpecial << endl;
}
