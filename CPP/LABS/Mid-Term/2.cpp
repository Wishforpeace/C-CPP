#include <iostream>

using namespace std;

class Person
{
protected:
    string name;
    string gender;
    string birth;
    int ID;

public:
    virtual void Display();
    Person(string name, string gender, string birth, int ID);
    Person(const Person &s)
    {
        this->birth = s.birth;
        this->gender = s.gender;
        this->name = s.name;
        this->ID = s.ID;
    }
};

Person ::Person(string name, string gender, string birth, int ID)
{
    this->name = name;
    this->gender = gender;
    this->birth = birth;
    this->ID = ID;
}

void Person::Display()
{
    cout << name << endl;
}

class Student : public Person
{
protected:
    string native_place;
    int student_id;
    int age;
    int score;

public:
    Student(string name, string gender, string birth, int ID, string native_place, int studentid, int age, int score);
    void Display();
    Student(const Student &s) : Person(s)
    {
        this->name = s.name;
        this->gender = s.gender;
        this->birth = s.birth;
        this->age = s.age;
        this->ID = s.ID;
        this->native_place = s.native_place;
        this->student_id = s.student_id;
        this->score = s.score;
    }
    Student operator+= (const Student &s) const;
};
Student::Student(string name, string gender, string birth, int ID, string native_place, int studentid, int age, int score) : Person(name, gender, birth, ID)
{
    this->native_place = native_place;
    this->student_id = studentid;
    this->age = age;
    this->score = score;
}

Student Student::operator+= (const Student &s) const
{

    int score_sum = this->score + s.score;
    cout << score_sum;
    Student New_Student("sum", "null", 0, 0, "null", 0, 0, score_sum);
    cout << New_Student.age;
    return New_Student;
}

void Student::Display()
{
    cout << "Student:" << endl;
    cout << "Basic info:" << endl;
    cout << "姓名\t性别\t出生日期\t身份ID\n";
    cout << this->name << "\t" << this->gender << "\t" << this->birth << "\t" << this->ID << endl;
    cout << "籍贯\t学号\t年龄\t成绩\n";
    cout << this->native_place << "\t" << this->student_id << "\t" << this->age << "\t" << this->score << endl;
}

class Teacher : public Person
{
protected:
    string position;

public:
    Teacher(string name, string gender, string birth, int ID, string position);
    void Display();
};

Teacher::Teacher(string name, string gender, string birth, int ID, string position) : Person(name, gender, birth, ID)
{
    this->position = position;
}

void Teacher::Display()
{
    cout << "Teacher:" << endl;
    cout << "Basic info:" << endl;
    cout << "姓名\t性别\t出生日期\t身份ID\n";
    cout << this->name << "\t" << this->gender << "\t" << this->birth << "\t" << this->ID << endl;
    cout << "职称" << endl;
    cout << this->position << endl;
}

class Stu_Teacher : virtual public Student, virtual public Teacher
{
public:
    Stu_Teacher(string name, string gender, string birth, int ID, string native_place, int studentid, int age, int score, string position);
    void Display();
};

Stu_Teacher::Stu_Teacher(string name, string gender, string birth, int ID, string native_place, int studentid, int age, int score, string position) : Student(name, gender, birth, ID, native_place, studentid, age, score), Teacher(name, gender, birth, ID, position)
{
}

void Stu_Teacher::Display()
{
    cout << "Student Teacher" << endl;
    // cout << "姓名\t性别\t出生日期\t身份ID\n";
    // cout << this->name << "\t" << this->gender << "\t" << this->birth << "\t" << this->ID << endl;
    // cout << "籍贯\t学号\t年龄\t成绩\n";
    // cout << this->native_place << "\t" << this->student_id << "\t" << this->age << "\t" << this->score << endl;
    // cout << "职称" << endl;
    // cout << this->position << endl;
}

int main()
{
    Person *p;
    // p.Display();

    Student s1("Hellen", "Female", "1998.05.09", 41223874, "江苏", 73913, 24, 78);
    p = &s1;
    p->Display();

    Student s2("Kate", "Female", "1997.06.09", 45523456, "湖北", 76153, 25, 89);
    p = &s2;
    p->Display();

    Student s3(s2);
    s3.Display();

    p = new Teacher("John", "Male", "1970.07.18", 68624053, "Professor");
    p->Display();

    Stu_Teacher st("Stephen", "Male", "1998.08.09", 65286523, "湖南", 56924, 24, 86, "助教");
    st.Display();

    s1 += s2;
}