#include <iostream>

using namespace std;

class Car
{
private:
    int power;
    int seat;

public:
    Car(int power, int seat)
    {
        this->power = power;
        this->seat = seat;
    }
    void
    Car();
};

Car::Car()
{
}
