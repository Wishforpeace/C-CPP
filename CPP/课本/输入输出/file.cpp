#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char line[80];
    fstream myfile;
    myfile.open("record.txt", ios::trunc | ios::out);
    if (!myfile)
    {
        cerr << "File open or create error!" << endl;
        exit(1);
    }
    while (cin.getline(line, 180))
    {
        myfile << line << endl;
    }
    myfile.close();
    return 0;
}