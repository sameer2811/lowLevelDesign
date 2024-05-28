#include <iostream>
using namespace std;
class IDrive
{
public:
    virtual void drive() = 0;
};

class SpecialDriveSrategy : public IDrive
{
public:
    void drive()
    {
        cout << "Speical Drive Strategy Pattern" << endl;
    }
};
class NormalDriveSrategy : public IDrive
{
public:
    void drive()
    {
        cout << "Normal Drive Strategy Pattern" << endl;
    }
};

class Vehicle
{
private:
    IDrive *driveStrategy;

public:
    Vehicle(IDrive *driveStrategy)
    {
        this->driveStrategy = driveStrategy;
    };

    void drive()
    {
        driveStrategy->drive();
    }
};

class OffRaodVehicle : public Vehicle
{

public:
    OffRaodVehicle() : Vehicle(new SpecialDriveSrategy())
    {
    }
};

class PassengerVehicle : public Vehicle
{
public:
    PassengerVehicle() : Vehicle(new SpecialDriveSrategy())
    {
    }
};

class SportsVehicle : public Vehicle
{

public:
    SportsVehicle() : Vehicle(new NormalDriveSrategy())
    {
    }
};

int main()
{
    Vehicle *v1 = new SportsVehicle();
    Vehicle *v2 = new PassengerVehicle();
    v1->drive();
    v2->drive();
}