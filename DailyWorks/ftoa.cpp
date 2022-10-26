#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

const double PI = 3.1415926;

class circle
{
    public:

    double radius;
    circle()
    {
        radius = 1;
    }
    circle(double newradius)
    {
        radius = newradius;
    }
    double area()
    {
        return PI * radius * radius;
    }
};

int main()
{
    std::vector <int> v;
    vector<vector<int> > matrix(4);
    for(int i = 0; i < 4; i++)
    {
        matrix[i] = vector <int> (3);
    }
    
    circle *p = new circle();
    cout << p->radius << " " << p->area() << endl; // also (*p).radius
    system("pause");
    return 0;
}