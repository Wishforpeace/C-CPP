#include <iostream>

using namespace std;

struct fmtflags
{
    long flag;
    char flagname[12];
} flags[18] = {
    {ios::hex, "hex"},
    {ios::dec, "dec"},
    {ios::oct, "oct"},
    {ios::basefield, "nasefield"},
    {ios::internal, "internal"},
    {ios::left, "left"},
    {ios::right, "right"},
    {ios::adjustfield, "adjustfield"},
    {ios::fixed, "fixed"},
    {ios::scientific, "scientific"},
    {ios::basefield, "basefield"},
    {ios::showbase, "showbase"},
    {ios::showpoint, "showpoint"},
    {ios::showpos, "showpos"},
    {ios::skipws, "skipws"},
    {ios::uppercase, "uppercase"},
    {ios::boolalpha, "boolalpha"},
    {ios::unitbuf, "unitbuf"}

};

int main()
{
    long IFlags;
    IFlags = cout.setf(0, cout.flags()); // 将格式状态清0,在将格式状态字0与0进行或运算
}