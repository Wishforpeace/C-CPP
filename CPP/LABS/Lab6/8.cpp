#include <iostream>

using namespace std;
// 职员
class employee
{
protected:
    int serial_num;
    string name;
    double wages;

public:
    employee();
    ~employee();
};

employee::employee(/* args */)
{
}

employee::~employee()
{
}

class manager : public employee
{
private:
    /* data */
public:
    manager : public employee(/* args */);
    ~manager : public employee();
};

manager : public employee::manager : public employee(/* args */)
{
}

manager : public employee::~manager : public employee()
{
}

class technician : public employee
{
private:
    /* data */
public:
    technician : public employee(/* args */);
    ~technician : public employee();
};

technician : public employee::technician : public employee(/* args */)
{
}

technician : public employee::~technician : public employee()
{
}

class salesman : public emloyee
{
private:
    /* data */
public:
    salesman : public emloyee(/* args */);
    ~salesman : public emloyee();
};

salesman : public emloyee::salesman : public emloyee(/* args */)
{
}

salesman : public emloyee::~salesman : public emloyee()
{
}

class salesmanager : public manager, public salesman
{
private:
    /* data */
public:
    salesmanager : public manager, public salesman(/* args */);
    ~salesmanager : public manager, public salesman();
};

salesmanager : public manager, public salesman::salesmanager : public manager, public salesman(/* args */)
{
}

salesmanager : public manager, public salesman::~salesmanager : public manager, public salesman()
{
}

int main()
{
}