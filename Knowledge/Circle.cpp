#include"Circle.h"

circle::circle()
{
    radius = 1;
}
circle::circle(double newradius)
{
    radius = newradius;
}
double circle::area()
{
    const double PI = 3.1415926535;
    return PI * radius * radius; 
}