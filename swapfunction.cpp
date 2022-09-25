#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iomanip>
#include<string>
#include<cctype>
#include<fstream>
using namespace std;

//tired...

void swap(int& num1,int& num2){}

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    cout<<"before:"<< a <<" "<< b;
    swap(a, b);
    cout<<"\nafter:"<< a <<" "<< b;
    system("pause");
    return 0; 
}


void swap(int& num1,int& num2)
{
    int num3 = 0;
    num3 = num1;
    num1 = num2;
    num2 = num3;
}
