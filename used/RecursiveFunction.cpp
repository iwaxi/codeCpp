#include<iostream>
#include<vector>
using namespace std;

//Recursive function 22/10/18 by iwaxi_dy
int trans(int n) // anti-order
{
    if(n)
    {
        cout << n % 10;
        trans(n / 10);
    }
    else
        return 0;
}

long long power(int a, int b) // a ** b
{
    if(b >= 1)
        return a * power(a, b - 1);
    else
        return 1;
}

int common(int a, int b) // the maximum common factor of a and b
{
    if(b)
        common(b, a % b);
    else
        return a;
}
int main()
{
    int number1 = 0, number2 = 0;
    cin >> number1 >> number2;
    long long pow = power(number1, number2);

    trans(number1);
    
    int com = common(number1, number2);
    cout << endl << com << endl;
    system("pause");
    return 0;
}