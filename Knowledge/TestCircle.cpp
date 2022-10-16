#include<iostream>
#include"Circle.h"

using namespace std;
int main()
{
    circle c1;
    double r = 0;
    cin >> r;
    c1 = circle();
    circle c2(r);
    cout << c1.area() << " " << c2.area() <<endl;
    system("pause");
    return 0;
}