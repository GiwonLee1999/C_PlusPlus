#include "Player.h"
#include "Country.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
#include <string>
using std::to_string;
using std::string;

// implementation of member function of the Player class
Player::Player(){
    numRegisteredPlayers++;
    name = "player" + to_string(numRegisteredPlayers);
};

string Player::getName(){
    return name;
}

// Initialization of static class member of the Player class
int Player::numRegisteredPlayers = 0;

// implementation of free operator
ostream& operator<<(ostream& os, Player& pl){
    os << pl.getName() << " : owned countries are: " << endl;
    for(Country* c: pl.ownedCountries){
        os << *c;
        cout << endl;
    }
    return os;
}

// declaration/initialization of a global variable
int numPlayers = 5;


