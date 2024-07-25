#pragma once
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <iostream>
using std::ostream;

class Country;

// class declaration
class Player
{
public:
    vector<Country*> ownedCountries;
    Player();
    string getName();
    static int numRegisteredPlayers;

private:
    string name;
};

// free operator declaration
ostream& operator<<(ostream& os, Player& pl);