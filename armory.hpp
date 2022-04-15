#ifndef armory_hpp
#define armory_hpp

#include <stdio.h>
#include <vector>
#include "weapons.hpp"
using namespace std;

class armory 
{
public:
    string armoryName;
    armory(string aName);
    int getPrice() const;
    void addWeapon(Weapons* w);
    void removeWeapon(Weapons* w);
private:
    vector <Weapons*> weapons;
};



#endif /* armory_hpp */
