#include <iostream>
using namespace std;
class Building
{
private:
    string name; //建筑名,即编号
    int floor;
    int room;
    float area;

public:
    Building(string name, int floor, int room, float area);
    void ShowInfo();
};

Building::Building(string name, int floor, int room, float area)
{
    this->name = name;
    this->floor = floor;
    this->room = room;
    this->area = area;
}

void Building::ShowInfo()
{
    cout << "建筑编号:" << this->name << endl;
    cout << "层数:" << this->floor << endl;
    cout << "房间数:" << this->room << endl;
    cout << "面积:" << this->area << " 平方米" << endl;
}

class TeachBuilding : public Building
{
private:
public:
    TeachBuilding(string name, int floor, int room, float area);
    void ShowInfo();
};

TeachBuilding ::TeachBuilding(string name, int floor, int room, float area) : Building(name, floor, room, area)
{
}
void TeachBuilding::ShowInfo()
{
    Building::ShowInfo();
}
class DormBuilding : public Building
{
private:
    int people;

public:
    DormBuilding(string name, int floor, int room, float, int people);
    void ShowInfo();
};

DormBuilding::DormBuilding(string name, int floor, int room, float area, int people) : Building(name, floor, room, area)
{
    this->people = people;
}
void DormBuilding::ShowInfo()
{
    cout << "--------------------------" << endl;
    Building::ShowInfo();
    cout << "容纳学生总人数:" << people << endl;
}
int main()
{
    TeachBuilding TB("南湖综合楼", 11, 200, 20000);
    TB.ShowInfo();
    DormBuilding DB("南湖10栋", 6, 100, 3000, 500);
    DB.ShowInfo();
}