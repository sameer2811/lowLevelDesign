/**
 * THIS PROGRAM DEMOSTRATES THE ABSTRACT FACTORY PATTERN METHOD FOR A FURNITURE FACTORY
 * SAME AS MAIN1.CPP BUT SLIGHT MODIFICATION IS DONE .
 * INSTEAD OF IMPLEMENTING ARMCHAIR , COFFETABLE SEPERATELY FOR EVERY FACTORY I HAVE IMPLEMENTED BOTH OF THEM IN SINGLE PIECE.
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

class RetroFurniturePiece : public ArmChair, public CoffeTable
{
public:
    void createArmChair()
    {
        cout << "Creating Arm Chair For Retro People" << endl;
    }
    void createCoffeTable()
    {
        cout << "Creating Coffe Table for Retro People" << endl;
    }
};

class ClassicFurniturePiece : public ArmChair, public CoffeTable
{
public:
    void createArmChair()
    {
        cout << "Creating Arm Chair For Classic People" << endl;
    }
    void createCoffeTable()
    {
        cout << "Creating Coffe Table for Classic People" << endl;
    }
};

class ModernFurniturePiece : public ArmChair, public CoffeTable
{
public:
    void createArmChair()
    {
        cout << "Creating Arm Chair For Modern People" << endl;
    }
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
        return new RetroFurniturePiece();
    }
    CoffeTable *createCoffeTable()
    {
        return new RetroFurniturePiece();
    }
};

class ModernFurnitureFactory : public FurnitureFactory
{
    ArmChair *createArmChair()
    {
        return new ModernFurniturePiece();
    }
    CoffeTable *createCoffeTable()
    {
        return new ModernFurniturePiece();
    }
};

class ClassFurnitureFactory : public FurnitureFactory
{
    ArmChair *createArmChair()
    {
        return new ClassicFurniturePiece();
    }
    CoffeTable *createCoffeTable()
    {
        return new ClassicFurniturePiece();
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
