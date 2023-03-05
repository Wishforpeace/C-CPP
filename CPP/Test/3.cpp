#include <iostream>
using namespace std;

class Con
{
    char ID;
    public:
    char getID()const{return ID;}
    Con():ID('A'){cout<<1;}
    Con(char ID):ID(ID){cout<<2;}
    Con(Con& c):ID(c.getID()){cout<<3;}
};

void show(Con c)