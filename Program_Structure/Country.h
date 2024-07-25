#pragma once
class Player;
#include <string>
using std::string;
#include <iostream>
using std::ostream;

class Country{
    public:
     Player * owner;
     Country();
     Country(Player* owner);
     string getName();
     static int numRegisteredCountries;
    private:
        string name;
};

// free operator declaration
ostream& operator<<(ostream& os, Country& co);