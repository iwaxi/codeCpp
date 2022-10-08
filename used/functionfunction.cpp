#include<iostream>//input/output stream
#include<cstdio>//standard i/o
#include<cstdlib>
#include<cmath>//math functions
#include<ctime>
#include<string>//string
#include<cctype>
#include<iomanip>
#include<fstream>//file stream

using namespace std;

void print(int n)
{
    if(n > 9)
    {
        print(n / 10);
    }
    printf("%d ", n % 10);
}

int main()
{
    int a = 0;
    cin >> a;
    print(a);
    system("pause");
    return 0;
}