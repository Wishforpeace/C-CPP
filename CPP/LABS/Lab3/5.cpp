#include <iostream>
#include <map>
using namespace std;

class Student
{
private:
    string StudentID;
    string Name;
    // 使用map来存放课程和对应成绩
    map<string, float> Curriculum;
    float average_score;

public:
    Student(string id, string name);
    ~Student();
    void Insert(string curriculum, float score);
    float Average();
};

Student::Student(string id, string name)
{
    this->StudentID = id;
    this->Name = name;
    // cout << this->StudentID << this->Name << endl;
}
void Student::Insert(string curriculum, float score)
{
    this->Curriculum.insert(pair<string, float>(curriculum, score));
    // cout<<Curriculum["English"]<<endl;
    float total = 0;
    for (auto iter = this->Curriculum.begin(); iter != this->Curriculum.end(); iter++)
    {
        // cout<<iter->first<<iter->second<<endl;
        total += iter->second;
    }
    this->average_score = total/3;
}

float Student::Average()
{
    return average_score;
}
Student::~Student()
{
}

int main()
{
    Student s[3] = {
        Student("1", "A"),
        Student("2", "B"),
        Student("3", "C"),
    };
    int i = 0;
    while (i < 3)
    {
        float score;
        cout<<"请输入学生"<<i+1<<"的成绩"<<endl;
        cout << "请输入数学成绩:";
        cin >> score;
        s[i].Insert("数学", score);
        cout << "请输入语文成绩:";
        cin >> score;
        s[i].Insert("语文", score);
        cout << "请输入英语成绩:";
        cin >> score;
        s[i].Insert("英语", score);
        i++;
    }
    float total;
    for (i = 0; i < 3; i++)
    {
        cout<<"学生"<<i+1<<"的成绩"<<s[i].Average()<<endl;
        total += s[i].Average();
    }

    cout << "所有学生平均成绩:" << total / 3 << endl;
}