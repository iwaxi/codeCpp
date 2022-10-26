#ifndef ClassNew_h
#define ClassNew_h

const double PI = 3.1415926;

class Classy
{
private:
    double radius;
    static int NumberOfMembers;

public:
    Classy();
    Classy(double);
    ~Classy();
    static int getNumber();
    double getArea();
};
#endif