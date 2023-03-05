#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char *name[3] = {"Antony", "John", "Tom"};
    float score[3] = {85.5, 90, 60};
    fstream txtfile, bindfile;
    txtfile.open("record.txt", ios::out | ios::trunc);
    bindfile.open("record.bat", ios::out | ios::trunc);
    if (!txtfile)
    {
        cerr << "record.txt open failed or create txt file error" << endl;
        exit(1);
    }

    if (!bindfile)
    {
        cerr << "record.bat open failed or create bat file error" << endl;
        exit(1);
    }

    for (int i; i < 3; i++)
    {
        txtfile << name[i] << '\t' << score[i] << endl;
        bindfile.write(name[i], 8 * sizeof(char));
        bindfile.write((char *)&score[i], sizeof(float));
    }
    txtfile.close();
    bindfile.close();
    return 0;
}