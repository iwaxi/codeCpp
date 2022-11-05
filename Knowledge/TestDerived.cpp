#include<iostream>
using namespace std;

class Geometry
{
public:
    Geometry(){
        name = "Default Geometry";
    }
    Geometry(string name): name(name){}

    virtual double getArea(){   // virtual function - dymanic
        return 0.0;
    }
    void print(){
        cout << "Geometry name: " << name << endl;
    }
private:
    string name;
};

class Circle : public Geometry
{
public:
    Circle(): Geometry(), radius(1){}
    Circle(int r, string name): Geometry(name), radius(r){}

    void print(){
        Geometry::print();
        cout << "And this is a r = " << radius << " circle.\n\n"; 
    }

    double getArea(){
        return 3.1415926 * radius * radius;
    }
private:
    int radius;
};

class Rectangle : public Geometry
{
public:
    Rectangle(): Geometry(), width(1), height(1){}
    Rectangle(int a, int b, string name): Geometry(name), width(a), height(b){}
    
    void print(){
        Geometry::print();
        cout << "And this is a width = " << width << ", height = " << height << " rectangle.\n\n";
    }

    double getArea(){
        return 1.0 * width * height;
    }
private:
    int width, height;
};


void getArea(Geometry *g){
    cout << "Area: " << g->getArea() << endl;
}

int main()
{
    Circle circle(2, "circle 1");
    Geometry *p = &circle;
    getArea(p);
    circle.print();

    Rectangle rec(4, 5, "rectangle 1");
    getArea(&rec);
    rec.print();
    
    system("pause");
    return 0;
}