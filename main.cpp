#include <iostream>
#include "weapons.hpp"
#include "gun.hpp"
#include "knife.hpp"
#include "crossbow.hpp"
#include "armory.hpp"
#include <vector>
using namespace std;
int main()
{
    vector <Weapons*> mass;
    cout << "Demonstration of Factory method pattern..." << endl << endl;
    try
    {
        mass.push_back(Weapons::createWeapon(WeaponType::CROSSBOW));
        mass.push_back(Weapons::createWeapon(WeaponType::KNIFE));
        mass.push_back(Weapons::createWeapon(WeaponType::GUN));
    }
    
    catch (runtime_error &err)
    {
        cout << err.what() << endl;
        return 0;
    }
    cout << endl;
    
    for (auto x: mass)
    {
        x->writeToStream(cout);
        cout << endl;
    }
    
    for (auto x: mass)
    {
        delete x;
    }
    cout << endl;
    
    cout << "---------------------------------------------------------" << endl << endl;
    cout << "Demonstration of Composite pattern..." << endl << endl;
    armory arm("Stalker");
    try
    {
        arm.addWeapon(Weapons::createWeapon(WeaponType::GUN));
        arm.addWeapon(Weapons::createWeapon(WeaponType::CROSSBOW));
    }
    catch (runtime_error &err)
    {
        cout << err.what() << endl;
    }
    cout << endl;
    cout << "All weapon worth in armory: " << arm.getPrice() << "$" << endl;
    cout << "\n";
    return 0;
}
