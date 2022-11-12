#include <iostream>

using namespace std;

class Clock
{
private:
    int hour, minute, second;

public:
    Clock(int h, int m, int s);
    void Display();
    Clock operator+(const Clock &c) const;
};

Clock::Clock(int h, int m, int s)
{
    this->hour = h % 24;
    this->minute = m % 60;
    this->second = s % 60;
}

Clock Clock::operator+(const Clock &c) const
{
    Clock NewClock(0, 0, 0);
    NewClock.hour = ((this->hour + c.hour) + (this->minute + c.minute + (this->second + c.second) / 60) / 60) % 24;
    NewClock.minute = ((this->minute + c.minute) + (this->second + c.second) / 60) % 60;
    NewClock.second = (this->second + c.second) % 60;
    return NewClock;
}

void Clock::Display()
{
    printf("%02d : %02d : %02d\n", hour, minute, second);
}
int main()
{
    Clock c1(3, 4, 5);
    cout << "Clock.1 is ";
    c1.Display();

    Clock c2(12, 40, 55);
    cout << "Clock.2 is ";
    c2.Display();

    cout << "Clock.1 + Clock.2 is "<<endl;
    (c1 + c2).Display();
}