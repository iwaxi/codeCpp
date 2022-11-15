#include<iostream>
using namespace std;
class myVector
{
private:
    int* elem;
    int space;
    int sz;
public:
    myVector(){
        space = 16;
        sz = 0;
        elem = new int[space];
    }
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
    void print(){
        for(int i = 0; i < sz; i++)
            cout << elem[i] << " ";
        cout << endl;
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
    int m = 0, n = 0;
    cin >> m >> n;
    myVector *v = new myVector[m];
    for(int i = 0; i < n; i++){
        int a = 0, t = 0;
        cin >> a >> t;
        switch (a){
            case 0:{
                int x = 0;
                cin >> x;
                (v + t)->pushBack(x);
            } break;
            case 1: (v + t)->print(); break;
            case 2: (v + t)->clear(); break;
        }
    }
    return 0;
}
