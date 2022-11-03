#include<iostream>
using namespace std;

class Rect
{
public:
    Rect(){
        w = h = 0;
        static int defaultTimes  = 0;
        defaultTimes ++;
        printf("Default Construct %d times.\n", defaultTimes);
    }
    Rect(int a){
        w = h = a;
        static int valueTimes = 0;
        valueTimes ++;
        printf("A Construct %d times.\n", valueTimes);
    }
    Rect(const Rect& a){
        w = a.w;
        h = a.h;
        static int copyTimes = 0;
        copyTimes ++;
        printf("Copy Construct %d times.\n", copyTimes);
    }
    ~Rect(){
        static int delTimes = 0;
        delTimes ++;
        printf("Delete %d times.\n", delTimes);
    }
    ostream& output(ostream& o) const{
        return o << w << " " << h;
    }
    
private:    
    int w, h;
};

void F(Rect a){
        return;
    }

int main()
{
    Rect a, b, *c, d[5], &e = d[4];
    F(3);
    Rect A = 3, B;
    B = 3;
    system("pause");
    return 0;
}