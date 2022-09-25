#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int min(int a, int b)
{
    int num1 = a,num2 = b;
    int min = 0;
    
    if(num1 <= num2)
        min = num1;
    else
        min = num2;
    return min;
}
int main()
{
    int a = 0,b = 0;
    cin >> a >> b;
    int mi = min(a,b);
    cout << mi <<endl;
    system("pause");
    return 0;
}