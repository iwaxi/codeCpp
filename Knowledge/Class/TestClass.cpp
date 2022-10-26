#include<iostream>
#include"ClassNew.h"
using namespace std;

int main()
{
    Classy* circle1 = new Classy();
    Classy* circle2 = new Classy(10.0);
    cout << Classy::getNumber() << " " << circle1->Classy::getArea() << endl;
    delete circle1;
    cout << Classy::getNumber() << " " << circle2->Classy::getArea() << endl;
    system("pause");
    return 0;
}