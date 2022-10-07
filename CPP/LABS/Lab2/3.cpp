#include <iostream>
using namespace std;

class Data
{
private:
    int year, month, day;

public:
    void Print();
    Data(int year, int month, int day);
    void NewDay();
    // 判断是闰年还是平年
    int LeapCommon();
    // 判断此月份天数
    int MonthDay();
};

Data::Data(int year, int month, int day)
{
    this->year = year;
    this->month = month;
    this->day = day;
}
void Data::Print()
{
    cout << "日期为:" << this->year << "年" << this->month << "月" << this->day << "日" << endl;
}

int Data::LeapCommon()
{
    if (this->year % 4 != 0)
    {
        return 0;
    }
    else if ((this->year % 100 == 0) && (this->year % 400 != 0))
    {
        return 0;
    }
    return 1;
}

int Data::MonthDay()
{
    int lm = this->LeapCommon();
    if (lm && this->month == 2)
    {
        return 29;
    }

    switch (this->month)
    {
    case 1:
        return 31;
    case 2:
        return 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31 ;
    default : break;
    }
    return 0;
}
void Data::NewDay()
{
    int D;
    D = this->day;
    // leap common
    int lm;
    int monthday;

    if (D + 1 > 28)
    {
       monthday = MonthDay();
       if(D+1>monthday)
       {
            if(this->month !=12)
            {
                this->month++;
                this->day = 1;
            }else
            {
                this->year++;
                this->day = 1;
                this->month = 1;
            }
       }else{
        this->day++;
       }
    }else{
        this->day++;
    }
}
int main()
{
    int year, month, day;
    cout << "请输入年:";
    cin >> year;
    cout << "月:";
    cin >> month;
    cout << "日:";
    cin >> day;
    Data data(year, month, day);
    data.Print();
    data.NewDay();
    cout<<"增加一天"<<endl;
    data.Print();
}