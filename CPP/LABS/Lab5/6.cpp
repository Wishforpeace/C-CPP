#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
using namespace std;

class Clock
{
private:
    int hour, minute, second;

public:
    Clock(int hour, int minute, int second);
    void Run();
    int getHour();
    int getMinute();
    int getSecond();
    void resetHour();
};

Clock::Clock(int hour, int minute, int second)
{
    this->hour = (hour > 23 ? hour % 24 : hour);
    this->minute = (minute > 60 ? minute % 60 : minute);
    this->second = (second > 60 ? second % 60 : second);
}

void Clock::Run()
{
    this->second++;
    if (this->second >= 60)
    {
        this->second = this->second % 60;
        this->minute++;
    }
    if (this->minute >= 60)
    {
        this->minute = this->minute % 60;
        this->hour++;
    }
}

int Clock::getHour()
{
    return this->hour;
}

int Clock::getMinute()
{
    return this->minute;
}

int Clock::getSecond();
{
    return this->second;
}
void Clock::resetHour()
{
    this->hour = this->hour % 24;
}

class Date
{
public:
    int year, month, day;
    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
};
class ClockWithDate : public Clock, public Date
{
private:
public:
    ClockWithDate(int year, int month, int day, int hour, int minute, int second) : Clock(hour, minute, second), Date(year, month, day){};
    void ShowDate();
    void DateRun();
};

void ClockWithDate::DateRun()
{
    while (1)
    {
        Clock::Run();
        if (Clock::getHour() >= 24)
        {

            this->day++;
            Clock::resetHour();
            switch (this->month)
            {
            case 1:
                if (this->day == 32)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 2:
                if (this->day == 29)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 3:
                if (this->day == 32)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 4:
                if (this->day == 31)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 5:
                if (this->day == 32)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 6:
                if (this->day == 31)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 7:
                if (this->day == 32)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 8:
                if (this->day == 32)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 9:
                if (this->day == 31)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 10:
                if (this->day == 32)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 11:
                if (this->day == 31)
                {
                    this->day = 1;
                    this->month++;
                }
                break;
            case 12:
                if (this->day == 32)
                {
                    this->day = 1;
                    this->month++;
                }
                break;

            default:
                break;
            }
        }
        if (this->month == 13)
        {
            this->month = 1;
            this->year++;
        }
        system("clear");
        cout << this->year << "-" << this->month << "-" << this->day << "  " << Clock::getHour() % 12 << ":" << Clock::getMinute() << ":" << Clock::getSecond() << endl;
        usleep(1000000);
    }
}
int main()
{
    ClockWithDate clock_with_date(2022,10,31,23,59,50);
    clock_with_date.DateRun();
}