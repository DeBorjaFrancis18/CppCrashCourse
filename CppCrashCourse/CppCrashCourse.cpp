#include <iostream>
using namespace std;

class Car {
private:
    string Color;
    double Price;
    
protected:
    string Name;
    bool isBroken;

public:
    Car(string name, string color, double price) {
        Name = name;
        Color = color;
        Price = price;
        isBroken = false;
    }
    void getInfo() {
        cout << "Name: " << Name << endl;
        cout << "Color: " << Color << endl;
        cout << "Price: " << Price << "Php" << endl;
    }
    void crashCar() {
        cout << Name << " crashed" << endl;
        isBroken = true;
    }
    void repairCar() {
        cout << Name << " repaired" << endl;
        isBroken = false;
    }
    void move() {
        if (isBroken) {
            cout << Name << " is broken" << endl;
        }
        else {
            cout << Name << " is driving" << endl;
        }
    }
};

class FlyingCar :public Car {
public:
    FlyingCar(string name, string color, double price):Car(name, color, price){
    }
    void move() {
        if (isBroken) {
            cout << Name << " is broken" << endl;
        }
        else {
            cout << Name << " is flying" << endl;
        }
    }
};
class UnderwaterCar:public Car {
public:
    UnderwaterCar(string name, string color, double price) :Car(name, color, price) {
    }
    void move() {
        if (isBroken) {
            cout << Name << " is broken" << endl;
        }
        else {
            cout << Name << " is diving" << endl;
        }
    }
};

int main()
{
    Car mazda("Mazda", "Red", 140000);
    FlyingCar flyingCar("Sky Fury", "Black", 500000);
    UnderwaterCar underwaterCar("Sea Storm", "Blue", 900000);
    
    mazda.move();
    flyingCar.move();
    underwaterCar.move();

    Car* car1 = &flyingCar;
    Car* car2 = &underwaterCar;
    car1->crashCar();
    car2->crashCar();

    mazda.move();
    flyingCar.move();
    underwaterCar.move();

    car1->repairCar();
    car2->repairCar();

    mazda.move();
    flyingCar.move();
    underwaterCar.move();

    system("pause>0");
}
