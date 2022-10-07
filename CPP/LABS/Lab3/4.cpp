#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
class Clock
{
private:
    int H, M, S, hour, minute, second;

public:
    Clock(int h, int m, int s);
    void SetAlarm(int h, int m, int s);
    void run();
};

Clock::Clock(int h, int m, int s)
{
    this->H = h;
    this->M = m;
    this->S = s;
}
// 设置闹铃
void Clock::SetAlarm(int h, int m, int s)
{
    this->hour = h;
    this->minute = m;
    this->second = s;
}
void Clock::run()
{
    while (1)
    {
        S++;
        if (S > 60)
        {
            M++;
            S = S % 60;
        }
        if (M > 60)
        {
            H++;
            M = M % 60;
        }
        system("clear");
        cout << H << ":" << M << ":" << S << endl;
        if((H == hour) && (M == minute) &&(S == second))
        {
            break;
        }
        usleep(1000000);
    }
    cout << "ding~~~~~~~~~" << endl;
}

int main()
{
    Clock clock(10, 10, 10);
    clock.SetAlarm(10, 10, 20);
    clock.run();
}