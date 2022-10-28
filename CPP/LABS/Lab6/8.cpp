#include <iostream>

using namespace std;

static int MaxNo = 0;
// 职员
class employee
{
protected:
    int serial_num;
    string name;
    double wages;

public:
    employee(string name);
    void pay();
    string GetName();
    int GetNo();
    double GetPayment();
};

employee::employee(string name)
{
    this->name = name;
    MaxNo++;
    this->serial_num = MaxNo;
    this->wages = 0.0;
}

string employee::GetName()
{
    return this->name;
}

int employee::GetNo()
{
    return this->serial_num;
}

double employee::GetPayment()
{
    return this->wages;
}

// 经理
class manager : virtual public employee
{
protected:
    double payment;
    double month_pay;

public:
    manager(string name, double month_pay);
    void pay();
};

manager ::manager(string name, double month_pay) : employee(name)
{
    this->month_pay = month_pay;
}

void manager::pay()
{
    this->wages = this->month_pay;
}
// 技术人员
class technician : public employee
{
protected:
    double hour;
    double hour_pay;

public:
    technician(string name, int hour_pay);
    void setHour(int hour);
    void pay();
};

technician ::technician(string name, int hour_pay) : employee(name)
{
    this->hour_pay = hour_pay;
}

void technician::setHour(int hour)
{
    this->hour = hour;
}

void technician::pay()
{
    this->wages = this->hour_pay * this->hour;
}

// 推销员
class salesman : virtual public employee
{
protected:
    double commission_rate;
    double sales;

public:
    salesman(string name, double commission_rate);
    void Setsales(double sales);
    void pay();
};

salesman ::salesman(string name, double commission_rate) : employee(name)
{
    this->commission_rate = commission_rate;
}

void salesman::Setsales(double sales)
{
    this->sales = sales;
}

void salesman::pay()
{
    this->wages = sales * commission_rate;
}

//销售经理
class salesmanager : virtual public manager, virtual public salesman
{
private:
public:
    salesmanager(string name, double month_pay, double commission_rate);
    void pay();
};
salesmanager::salesmanager(string name, double month_pay, double commission_rate) : manager(name, month_pay), salesman(name, commission_rate), employee(name)
{
}

void salesmanager::pay()
{
    this->wages = this->month_pay + this->commission_rate * this->sales;
}

int main()
{
    manager m("John", 8000);
    m.pay();
    cout << "经理: " << m.GetName() << " 的收入: " << m.GetPayment() << "元" << endl;

    technician t("Billy", 100);
    t.setHour(160);
    t.pay();
    cout << "技术人员:" << t.GetName() << " 工作时长为160h,收入为: " << t.GetPayment() << "元" << endl;

    salesman s("Tom", 0.04);
    s.Setsales(8000);
    s.pay();
    cout << "销售员:" << s.GetName() << " 销售额为800,收入为: " << s.GetPayment() << "元" << endl;

    salesmanager sm("Mike", 5000, 0.05);
    sm.Setsales(10000);
    sm.pay();
    cout << "销售经理:" << sm.GetName() << " 销售额为1000,收入为: " << sm.GetPayment() << "元" << endl;
}