#include <iostream>
#include "date.h"
using std::endl;
using std::cout;

int main(){
    date *dt = new date();
    dt->setDate(12,4);
    dt->getDate();
    dt->getMonth();
    dt->getDay();
    
    return 0;
};
void date::setDate(int month, int day){
    this->month = month;
    this->day = day;
};

void date::getDate{
    cout << "Month: " << month << " Day is: " << day << endl;
};

void date::getDay{
    cout << "Day is: " << day << endl;
};

void date::getMonth{
    cout << "Month: " << month << endl;
};