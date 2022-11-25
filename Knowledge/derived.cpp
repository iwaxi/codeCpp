#include<iostream>
using namespace std;

class Vec2D
{
public:
    Vec2D(): x(0), y(0){cout << "Def 0 0\n";}
    Vec2D(int a, int b = 2): x(a), y(b){cout << "Cons a b\n";}
    Vec2D(const Vec2D& v): x(v.x), y(v.y){cout << "copy const&\n";}
    Vec2D(Vec2D&& v): x(v.x), y(v.y) {cout << "copy &&\n";}
    Vec2D(Vec2D& v): x(v.x), y(v.y){cout << "copy &\n";}
    // Vec2D(Vec2D v): x(v.x), y(v.y){cout << "copy vec\n";}
    virtual int square(){
        return x * x + y * y;
    }
private:
    int x;
    int y;
};

class Vec3D : public Vec2D
{
public:
    Vec3D(): Vec2D(), z(0){}
    Vec3D(int a, int b, int c): Vec2D(a, b), z(c){}
    int square(){
        return Vec2D::square() + z * z;
    }
private:
    int z;
};

Vec2D fun(Vec2D v){
    return v;
}

int main()
{
    Vec2D a(1, 2);
    Vec2D c;
    Vec2D d = c;
    Vec2D b = 1;
    Vec3D v(1, 2, 3);
    Vec2D& vv = v;
    fun(c);
    cout << vv.square() << endl; 
    return 0;
}