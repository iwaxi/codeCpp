#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int f(int);

int main()
{
    auto (*p) (int) = f;    // function pointer
    int a = f(2);
    int b = p(4);
    int c = (*p)(6);
    cout << a << " " << b << " " << c << endl;

    ofstream o;
    o.open("c://Users//iwaxi//Desktop//file.txt", ios::app);
    /*o << endl << a << " " << b << " " << c << endl;
    srand(time(0));
    for(int i = 0; i < 10; i++)
        o << rand() % 50 << " ";*/
    o << endl << reinterpret_cast<long long*>(b) << endl;
    o.close();
    return 0;
}

auto f(int a) -> int32_t{
    return 2 * a;
}