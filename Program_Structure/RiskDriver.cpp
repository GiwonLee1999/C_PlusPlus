
#include <iostream>
#include <string>
using std::cout;
#include <vector>
using std::vector;
#include "Player.h"
#include "Country.h"

// global variables declared in Player.cpp and Country.cpp
extern int numPlayers;
extern int numCountries;

int main(){
    vector<Player*> allPlayers;
    vector<Country*> allCountries;
    
    for( int i = 1; i <= numPlayers; i++)
        allPlayers.push_back(new Player());
    
    for( int j = 0; j <= numCountries - 1; j++)
        allPlayers.at(j % numPlayers)->ownedCountries.push_back(new Country(allPlayers.at( j % numPlayers )));
    
    for( int k = 0 ; k <= numPlayers - 1; k++)
        cout << *allPlayers.at(k);
    
};