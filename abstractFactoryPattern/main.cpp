/**
 * THIS PROGRAM DEMOSTRATES THE ABSTRACT FACTORY PATTERN METHOD FOR A FURNITURE FACTORY.
 */
#include <iostream>
using namespace std;
class ArmChair
{
public:
    virtual void createArmChair() = 0;
};

class CoffeTable
{
public:
    virtual void createCoffeTable() = 0;
};

class RetroArmChair : public ArmChair
{
public:
    void createArmChair()
    {
        cout << "Creating Arm Chair For Retro People" << endl;
    }
};

class RetroCoffeTable : public CoffeTable
{
public:
    void createCoffeTable()
    {
        cout << "Creating Coffe Table for Retro People" << endl;
    }
};

class ClassicArmChair : public ArmChair
{
public:
    void createArmChair()
    {
        cout << "Creating Arm Chair For Classic People" << endl;
    }
};

class ClassicCoffeTable : public CoffeTable
{
public:
    void createCoffeTable()
    {
        cout << "Creating Coffe Table for Classic People" << endl;
    }
};

class ModernArmChair : public ArmChair
{
public:
    void createArmChair()
    {
        cout << "Creating Arm Chair For Modern People" << endl;
    }
};

class ModernCoffeTable : public CoffeTable
{
public:
    void createCoffeTable()
    {
        cout << "Creating Coffe Table for Modern People" << endl;
    }
};

class FurnitureFactory
{
public:
    virtual ArmChair *createArmChair() = 0;
    virtual CoffeTable *createCoffeTable() = 0;
};

class RetroFurnitureFactory : public FurnitureFactory
{
    ArmChair *createArmChair()
    {
        return new RetroArmChair();
    }
    CoffeTable *createCoffeTable()
    {
        return new RetroCoffeTable();
    }
};

class ModernFurnitureFactory : public FurnitureFactory
{
    ArmChair *createArmChair()
    {
        return new ModernArmChair();
    }
    CoffeTable *createCoffeTable()
    {
        return new ModernCoffeTable();
    }
};

class ClassFurnitureFactory : public FurnitureFactory
{
    ArmChair *createArmChair()
    {
        return new ClassicArmChair();
    }
    CoffeTable *createCoffeTable()
    {
        return new ClassicCoffeTable();
    }
};

FurnitureFactory *getFactoryObject(string type)
{
    if (type == "retro")
    {
        return new RetroFurnitureFactory();
    }
    else if (type == "classic")
    {
        return new ClassFurnitureFactory();
    }
    else
    {
        return new ModernFurnitureFactory();
    }
}

int main()
{
    string type;
    cout << "Which among the follwing you want to take factory --> retro , classic , modern product" << endl;
    cin >> type;

    FurnitureFactory *factory = getFactoryObject(type);
    factory->createArmChair()->createArmChair();
    factory->createCoffeTable()->createCoffeTable();
}
