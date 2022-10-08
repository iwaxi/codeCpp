#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<cstring>
using namespace std;

int main()
{
    int a = 0;
    cin >> a;
    int *p = &a; // initialize a point with location of a 
    cout << p <<" " << &a <<endl;
    cout << *p <<" " << a <<endl; // rebuild point p as vaule of a
    
    char city[30] = "Oh";
    strcpy(city,"New");
    cout << city << endl;
    strcat(city, " Old");
    cout << city << endl;
    int i;
    i =  strlen(city);
    cout << i <<"\n";
    for(int j = 0; j < 9; j++)
        cout <<"*"<<endl;


    system("pause");
    return 0;
}
