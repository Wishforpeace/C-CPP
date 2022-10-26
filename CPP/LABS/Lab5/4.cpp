#include <iostream>

using namespace std;

class Person
{
private:
    string Name;
    string Gender;
    string ID;
    string Birth;

public:
    Person(string name, string gender, string id, string birth)
    {
        this->Name = name;
        this->Gender = gender;
        this->ID = id;
        this->Birth = birth;
    };
    void display()
    {
        cout << "姓名：" << this->Name << endl;
        cout << "性别：" << this->Gender << endl;
        cout << "身份证：" << this->ID << endl;
        cout << "出生日期：" << this->Birth << endl;
    };
};

class Teacher : virtual public Person
{
private:
    string Profession;

public:
    Teacher(string name, string gender, string id, string birth, string profession) : Person(name, gender, id, birth)
    {
        this->Profession = profession;
    };
    void display()
    {

        cout << "职称：" << this->Profession << endl;
    };
};
class Student : virtual public Person
{
private:
    string StudentID;
    string Grade;

public:
    Student(string name, string gender, string id, string birth, string stu_id, string grade) : Person(name, gender, id, birth)
    {
        this->StudentID = stu_id;
        this->Grade = grade;
    }
    void display()
    {

        cout << "学号：" << this->StudentID << endl;
        cout << "成绩：" << this->Grade << endl;
    }
};

class Stu_Teach : public Student,
                  public Teacher
{
private:
public:
    Stu_Teach(string name, string gender, string id, string birth, string profession, string stu_id, string grade)
        : Person(name, gender, id, birth), Student(name, gender, id, birth, stu_id, grade), Teacher(name, gender, id, birth, profession){};
    void display()
    {
        Person::display();
        Student::display();
        Teacher::display();
    }
};

int main()
{
    Stu_Teach ST("Barry Allen", "Male", "201831031", "1999年1月1日", "助教", "186836131", "89");
    ST.display();
    return 0;
}