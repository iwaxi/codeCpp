#include<iostream>

using namespace std;

int DigitSum(int n)
{
    if(n)
        return ( n % 10 + DigitSum(n / 10));
    else
        return 0;
}

int main()
{
    int num = 0;
    cin >> num;
    int SUM = DigitSum(num);
    cout << SUM <<endl;
    system("pause");
    return 0;
}