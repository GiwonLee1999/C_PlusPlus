
#include <iostream>
using std::ostream;
using std::endl;
#include <string>
using std::to_string;
#include "Player.h"
#include "Country.h"
// implementation of member function of the Player class
Country::Country(): owner(NULL), name(""){
    numRegisteredCountries++;
}
Country::Country(Player * owner): owner(owner){
    numRegisteredCountries++;
    name = "country" + to_string(numRegisteredCountries);
}

string Country::getName(){
    return name;
}



// static class member of the player class
int Country::numRegisteredCountries = 0;


// implementation of free operator
ostream& operator<<(ostream& os, Country & co){
    os << co.getName() << " : owner is " << co.owner->getName() << endl;
    return os;
}

// declaration/initialization of a global variable
int numCountries = 13;