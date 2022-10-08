#include<iostream>
#include<bits\stdc++.h>
#include<iomanip>
using namespace std;
const double PI = 3.1415926;
class Circle
{
    public: //data field
        double radius;
        double x,y;

        Circle()//construct function, name must be the same as class
        {
            radius = 1;
        }

        Circle(double newRadius)
        {
            radius = newRadius;
        }

        double Area()//function
        {
            return radius * PI * radius;
        }
};

int main()
{
    typedef int * intPoint;
    int a = 0;
    intPoint p = &a;
    printf("%d\n",p);
    cout << *p << endl;
    cout << p << endl;

    Circle circle1(2);
    Circle c3;
    c3.x = 4; c3.y = 2;
    Circle c2;
    cout << "radius:" << circle1.radius << " Area:" << circle1.Area() <<endl;
    cout << "radius:" << c2.radius <<" Area:" << c2.Area() << endl;
    cout << "\nx:" << c3.x <<" y:" << c3.y << endl;
    
    cout << fixed << setprecision(6) << PI <<endl;
    
    cout << resetiosflags(ios::fixed) << setiosflags(ios::scientific) <<setprecision(6) << PI <<endl;
    int num = 0x123'full;
    cout << num <<"\n";
    assert(num == 0x123 * 16 +15);
    cout << num ;
    system("pause");
    return 0;
}