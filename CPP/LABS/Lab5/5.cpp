#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class Clock
{
private:
    int hour, minute, second;

public:
    Clock(int hour, int minute, int second)
    {
        this->hour = (hour > 23 ? hour % 24 : hour);
        this->minute = (minute > 60 ? minute % 60 : minute);
        this->second = (second > 60 ? second % 60 : second);
    };
    virtual void Run();
    int GetHour()
    {
        return this->hour;
    };
    int GetMinute()
    {
        return this->minute;
    };
    int GetSecond()
    {
        return this->second;
    };
};

void Clock::Run()
{

    this->second++;
    if (this->second >= 60)
    {
        this->minute++;
        this->second = this->second % 60;
    }
    if (this->minute >= 60)
    {
        this->hour++;
        this->minute = this->minute % 60;
    }

    // cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}

class NewClock : public Clock
{
private:
    string Meridiem;

public:
    NewClock(int hour, int minute, int second) : Clock(hour, minute, second)
    {
        cout << "init" << endl;
        if (NewClock::GetHour() > 12)
        {
            this->Meridiem = "PM";
        }
        else
        {
            this->Meridiem = "AM";
        }
    };
    void ShowTime()
    {
        if (NewClock::GetHour() > 12)
        {
            system("clear");
            cout << NewClock::GetHour() % 12 << ":" << NewClock::GetMinute() << ":" << NewClock::GetSecond() << this->Meridiem << endl;
        }
        else
        {
            system("clear");
            cout << NewClock::GetHour() << ":" << NewClock::GetMinute() << ":" << NewClock::GetSecond() << this->Meridiem << endl;
        }
    };
    void RunNew()
    {
        while (1)
        {
            NewClock::Run();
            usleep(1000000);
            ShowTime();
        }
    };
};

int main()
{
    // Clock clock(10, 10, 10);
    // cout << clock.GetHour() << endl;
    NewClock newclock(10, 10, 10);
    newclock.RunNew();
}