#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string StudentID;
    string Name;
    string Password;

public:
    Student(string id, string name, string password);
    ~Student();
    bool login(string id, string password);
};

Student::Student(string id, string name, string password)
{
    this->StudentID = id;
    this->Name = name;
    int i;
    for (i = 0; i < password.size(); i++)
    {
        password[i] = password[i] + 10;
    }
    this->Password = password;
    // cout << this->Password << endl;
}

Student::~Student()
{
}

bool Student::login(string id, string pw)
{
    int i;
    if (id != this->StudentID)
    {
        return false;
    }
    if (pw.size() != this->Password.size())
    {
        return false;
    }
    for (i = 0; i < pw.size(); i++)
    {
        if (pw[i] + 10 != this->Password[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string StudentID, Name, Password;
    cout << "请注册:" << endl;
    cout << "请输入学号:";
    cin >> StudentID;
    cout << "请输入姓名:" << endl;
    cin >> Name;
    cout << "请输入密码:" << endl;
    cin >> Password;
    Student stu(StudentID, Name, Password);
    cout << "请登录" << endl;
    cout << "学号:";
    cin >> StudentID;
    cout << "密码:";
    cin >> Password;
    bool status;
    status = stu.login(StudentID, Password);
    if (status)
    {
        cout << "登录成功" << endl;
    }
    else
    {
        cout << "登录失败，密码或账号错误" << endl;
    }
}