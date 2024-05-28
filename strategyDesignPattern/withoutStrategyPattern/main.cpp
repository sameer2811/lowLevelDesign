
#include <iostream>
using namespace std;

class Vehicle
{
public:
    void drive()
    {
        cout << "Driving the Normal Capability" << endl;
    }
};

class OffRaodVehicle : public Vehicle
{

public:
    void drive()
    {
        cout << "Driving the Special Capability" << endl;
    }
};

class PassengerVehicle : public Vehicle
{
};

class SportsVehicle : public Vehicle
{

public:
    void drive()
    {
        cout << "Driving the Special Capability" << endl;
    }
};

int main()
{

    SportsVehicle p1;
    PassengerVehicle p2;
    OffRaodVehicle p3;

    p1.drive();
    p2.drive();
    p3.drive();
}
