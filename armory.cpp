#include "armory.hpp"

armory::armory(string aName)
{
    armoryName = aName;
    
}

int armory::getPrice() const
{
    int price = 0;
    for (auto x : weapons)
        price += x->getPrice();
    return price;
}

void armory::addWeapon(Weapons* w)
{
    for (auto x : weapons)
    {
        if (x->getID() == w->getID())
            throw runtime_error("Duplicate of weapon in armory!");
    }
    weapons.push_back(w);
}

void armory::removeWeapon(Weapons* w)
{
    for (auto x = weapons.begin(); x != weapons.end(); x++)
    {
        if ((*x)->getID() == w->getID())
            weapons.erase(x);
        return;
    }
    throw runtime_error("Missing weapon with such ID in armory!");
}
