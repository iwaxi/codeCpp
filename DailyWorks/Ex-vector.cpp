#include<iostream>
using namespace std;
class myVector
{
private:
    int* elem;
    int space;
    int sz;
public:
    myVector(): space(16), sz(0), elem(new int[space]{}){}
    void checkSize(){
        if(sz + 1 >= space){
            space *= 2;
            int* New = new int[space]{};
            delete[] elem;
            elem = New;
        }
    }
    void pushBack(int n){
        checkSize();
        elem[sz++] = n;
    }
    void popBack(){
        sz --;
    }
    void randomAccess(int p){
        cout << elem[p] << endl;
    }
    void clear(){
        sz = space = 0;
        if(elem) delete[] elem;
    }
    ~myVector(){
        sz = space = 0;
        if(elem) delete[] elem;
    }
};
int main()
{
    myVector v;
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a = 0;  cin >> a;
        switch (a){
        case 0:{
            int m = 0;
            cin >> m;
            v.pushBack(m);
        } break;
        case 1:{
            int p = 0;
            cin >> p;
            v.randomAccess(p);
        } break;
        case 2:
            v.popBack();
            break;
        }
    }
    return 0;
}
