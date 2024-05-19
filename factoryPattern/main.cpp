
/**
 * THIS PROGRAM TELLS THE BASIC USAGE OF FACTORY DESIGN PATTERN
*/
#include <iostream>
using namespace std;
class IVehicleFactory
{
public:
    virtual void createVehicle() = 0;
};

class Bike : public IVehicleFactory
{
public:
    void createVehicle()
    {
        cout << "Creating the Bike Vehicle" << endl;
    }
};

class Car : public IVehicleFactory
{
public:
    void createVehicle()
    {
        cout << "Creating the Car Vehicle" << endl;
    }
};

IVehicleFactory *getVehicleObject(string type)
{
    if (type == "bike")
    {
        return new Bike();
    }
    else if (type == "car")
    {
        return new Car();
    }
    return new Car();
}

int main()
{
    string type;
    cout << "Please Provide the type of vehicle you want to create" << endl;
    cin >> type;
    IVehicleFactory *factory = getVehicleObject(type);
    factory->createVehicle();
}