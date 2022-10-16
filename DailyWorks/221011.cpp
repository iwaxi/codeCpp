#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

void trans(char* ch1, char* ch2, int n)
{
    for(int i = 0; i < n; i++)
    {
        ch2[i] = ch1[n - i -1];
    }
}
bool ispalnum(int n)
{
    char ch[4] = "";
    int k = 0;
    while(n)
    {
        ch[k] = char(n % 10 - '0');
        n /= 10;
        k++;
    }
    int size = strlen(ch);
    char ch_t[4] = "";
    trans(ch, ch_t, size);
    bool b = !strcmp(ch, ch_t);
    return b;
}
bool isprime(int n)
{
    int divide = 0;
    for(int i = 1; i < n; i++)
    {
        if( n % i == 0)
            divide++;
    }
    bool c = divide - 1;
    return c;
}
int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    while(a || b)
    {
        for(int i = a; i <= b; i++)
        {
            if(ispalnum(i) && !isprime(i))
                cout << i <<endl;
        }
        cout << endl;
        cin >> a >> b;
    }
    system("pause");
    return 0;
}