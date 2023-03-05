#ifndef delete2dArray_
#define delete2dArray_

using namespace std;

template <class T>
void delete2dArray(T **&theArray, int numberofRows)
{
    for (int i = 0; i < numberofRows; i++)
    {
        delete[] theArray[i];
    }
    delete[] theArray;
    theArray = 0;
}

#endif