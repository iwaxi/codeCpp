#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cctype>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

void out(const int list[], int Size)
{
    for(int i = 0; i < Size; i++)
        cout << list[i] <<" ";
}

int main()
{
    const int ArraySize = 5;
    int list[ArraySize] = {};
    for(int i = 0; i < ArraySize; i++)
        cin >> list[i];
    
    int min = 0;
    for(int i = 0; i < ArraySize; i++)
        if(min >= list[i])
            min = list[i] - 1;
    
    int order[ArraySize] = {};
    for(int i = 0; i < ArraySize; i++)
        order[i] = min;

    for(int i = 0; i < ArraySize; i++)
    {
        int b = 0;
        for(int j = 0; j < ArraySize; j++)
            if(order[i] <= list[j])
            {
                order[i] = list[j];
                b = j;
            }
        list[b] = min;
    }
    out(order, ArraySize);
    system("pause");
    return 0;
}