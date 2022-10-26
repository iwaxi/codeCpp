#include"ClassNew.h"
int Classy::NumberOfMembers = 0;
Classy::Classy()
{
    radius = 1;
    NumberOfMembers ++;
}
Classy::Classy(double newradius)
{
    this->radius = newradius;
    NumberOfMembers ++;
}
Classy::~Classy()
{
    NumberOfMembers --;
}
int Classy::getNumber()
{
    return NumberOfMembers;
}
double Classy::getArea()
{
    return PI * radius * radius;
}