#include<iostream>//i/o stream
#include<cstdio>//standard i/o
#include<cstdlib>
#include<cmath>//math
#include<ctime>
#include<string>//string
#include<cctype>//character
#include<iomanip>
#include<fstream>//file stream
#include<bits/stdc++.h>//almost everything
using namespace std;

void in(int list[], int Size)
{
    for(int i = 0; i < Size; i++)
        cin >> list[i];
}

void out(int list[], int Size)
{
    for(int i = 0; i < Size; i++)
        cout << list[i] <<" ";
}

int main()
{
    const int Size = 5;
    int array[Size] = {};
    in(array, Size);
    out(array, Size);
    system("pause");
    return 0;
}